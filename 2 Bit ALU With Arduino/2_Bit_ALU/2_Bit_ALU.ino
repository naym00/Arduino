int S0, S1, S2, A[2], B[2], Output[2], COUT, bitSize = 2;
void setup() {
  Serial.begin(9600);

  //SWITCH
  pinMode(5, INPUT); //S0
  pinMode(4, INPUT); //S1
  pinMode(3, INPUT); //S2

  //INPUT
  pinMode(7, INPUT); //A[0]
  pinMode(6, INPUT); //A[1]
  pinMode(9, INPUT); //B[0]
  pinMode(8, INPUT); //B[1]

  //OUTPUT
  pinMode(10, OUTPUT); //Output[0]
  pinMode(11, OUTPUT); //Output[1]
  pinMode(12, OUTPUT); //COUT
}
//      S2     S1     S0     Operation  
//      0      0      0         A+B
//      0      0      1         A-B
//      0      1      0         A-1
//      0      1      1         A+1
//      1      0      0         AND
//      1      0      1         OR
//      1      1      0         NOT
//      1      1      1         XOR

void loop() {
  S0 = digitalRead(5);
  S1 = digitalRead(4);
  S2 = digitalRead(3);

  A[0] = digitalRead(7);
  A[1] = digitalRead(6);
  B[0] = digitalRead(9);
  B[1] = digitalRead(8);

  //S2 S1 S0
  if (S2 == LOW && S1 == LOW && S0 == LOW)
  {
    //A+B
    FULLADDER(0);
    digitalWrite(10, Output[0]);
    digitalWrite(11, Output[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == LOW && S1 == LOW && S0 == HIGH)
  {
    //A-B
    NOT(B);
    FULLADDER(1);
    COUT=LOW;
    digitalWrite(10, Output[0]);
    digitalWrite(11, Output[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == LOW && S1 == HIGH && S0 == LOW)
  {
    //A-1
    B[0] = HIGH;
    B[1] = HIGH;
    FULLADDER(0);
    COUT=LOW;
    digitalWrite(10, Output[0]);
    digitalWrite(11, Output[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == LOW && S1 == HIGH && S0 == HIGH)
  {
    //A+1
    B[0] = HIGH;
    B[1] = LOW;
    FULLADDER(0);
    digitalWrite(10, Output[0]);
    digitalWrite(11, Output[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == HIGH && S1 == LOW && S0 == LOW)
  {
    //A AND B
    AND();
    digitalWrite(10, Output[0]);
    digitalWrite(11, Output[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == HIGH && S1 == LOW && S0 == HIGH)
  {
    //A OR B
    OR();
    digitalWrite(10, Output[0]);
    digitalWrite(11, Output[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == HIGH && S1 == HIGH && S0 == LOW)
  {
    // NOT A
    NOT(A);
    Output[0]=A[0];
    Output[1]=A[1];
    digitalWrite(10, Output[0]);
    digitalWrite(11, Output[1]);
    digitalWrite(12, COUT);

  }
  else if (S2 == HIGH && S1 == HIGH && S0 == HIGH)
  {
    // A XOR B
    XOR();
    digitalWrite(10, Output[0]);
    digitalWrite(11, Output[1]);
    digitalWrite(12, COUT);
  }
}

void FULLADDER(int zeroOne)
{
  // For ADD Operation COUT has to be initialized by LOW
  // For ADD Operation COUT has to be initialized by HIGH
  if(zeroOne == 0)
    COUT = LOW;
  else
    COUT = HIGH;
  for (int i = 0; i < bitSize; i++)
  {
    Output[i] = (A[i]+B[i]+COUT)%2;
    COUT = (A[i]+B[i]+COUT)/2;
  }
}
void NOT(int *X)
{
  for (int i = 0; i < bitSize; i++)
  {
    if (*(X + i) == HIGH)
      *(X + i) = LOW;
    else
      *(X + i) = HIGH;
  }
  COUT = LOW;
}
void AND()
{
  for (int i = 0; i < bitSize; i++)
  {
    if (A[i] == HIGH && B[i] == HIGH)
      Output[i] = HIGH;
    else
      Output[i] = LOW;
  }
  COUT = LOW;
}
void OR()
{
  for (int i = 0; i < bitSize; i++)
  {
    if (A[i] == LOW && B[i] == LOW)
      Output[i] = LOW;
    else
      Output[i] = HIGH;
  }
  COUT = LOW;
}
void XOR()
{
  for (int i = 0; i < bitSize; i++)
  {
    if ((A[i] == LOW && B[i] == LOW) || (A[i] == HIGH && B[i] == HIGH))
      Output[i] = LOW;
    else
      Output[i] = HIGH;
  }
  COUT = LOW;
}


