int fourDigit[4];
int numberPositionStatus[4];
void setup()
{
  for (int i = 2; i <= 12; i++)
  {
    pinMode (i, OUTPUT);
  }
  //Pin 2-8 Will be dedicated for 7 Segment
  //Pin 9-12 will be dedicated for switching button for 7SEG-MPX4-CA
  //          ......                 ......                  ......                 ......
  //          . 12 .                 . 11 .                  . 10 .                 .  9 .
  //          ......                 ......                  ......                 ......

  //       fourDigit[3]            fourDigit[2]           fourDigit[1]            fourDigit[0]
  //  numberPositionStatus[3] numberPositionStatus[2] numberPositionStatus[1] numberPositionStatus[0]
}
void loop()
{
  for (int i = 1000; i >= 0; i--)
  {
    displayOff();
    fourDigit[3] = i / 1000;
    fourDigit[2] = (i % 1000) / 100;
    fourDigit[1] = ((i % 1000) % 100) / 10;
    fourDigit[0] = ((i % 1000) % 100) % 10;
    if (i >= 1000)
    {
      numberPositionStatus[3] = HIGH;
      numberPositionStatus[2] = HIGH;
      numberPositionStatus[1] = HIGH;
      numberPositionStatus[0] = HIGH;
    }
    else if (i >= 100)
    {
      numberPositionStatus[3] = LOW;
      numberPositionStatus[2] = HIGH;
      numberPositionStatus[1] = HIGH;
      numberPositionStatus[0] = HIGH;
    }
    else if (i >= 10)
    {
      numberPositionStatus[3] = LOW;
      numberPositionStatus[2] = LOW;
      numberPositionStatus[1] = HIGH;
      numberPositionStatus[0] = HIGH;
    }
    else
    {
      numberPositionStatus[3] = LOW;
      numberPositionStatus[2] = LOW;
      numberPositionStatus[1] = LOW;
      numberPositionStatus[0] = HIGH;
    }
    // If you want to slow down then you can reduce 150 to any other lower number.
    // If you want to speed up then you can increase 150 to any other bigger number.
    for (int j = 1; j <= 150; j++)
    {
      if (numberPositionStatus[3] == HIGH)
      {
        displayOff();
        digitalWrite(12, numberPositionStatus[3]);
        onNumber(fourDigit[3]);
      }
      if (numberPositionStatus[2] == HIGH)
      {
        displayOff();
        digitalWrite(11, numberPositionStatus[2]);
        onNumber(fourDigit[2]);
      }
      if (numberPositionStatus[1] == HIGH)
      {
        displayOff();
        digitalWrite(10, numberPositionStatus[1]);
        onNumber(fourDigit[1]);
      }
      if (numberPositionStatus[0] == HIGH)
      {
        displayOff();
        digitalWrite(9, numberPositionStatus[0]);
        onNumber(fourDigit[0]);
      }
    }
  }
}
void onNumber(int number)
{
  if (number == 0)
  {
    digitalWrite (2, HIGH);
    digitalWrite (3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (6, HIGH);
    digitalWrite (7, HIGH);
    digitalWrite (8, LOW);
    delay(1);
  }
  else if (number == 1)
  {
    digitalWrite (2, LOW);
    digitalWrite (3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite (5, LOW);
    digitalWrite (6, LOW);
    digitalWrite (7, LOW);
    digitalWrite (8, LOW);
    delay(1);
  }
  else if (number == 2)
  {
    digitalWrite (2, HIGH);
    digitalWrite (3, HIGH);
    digitalWrite (4, LOW);
    digitalWrite (5, HIGH);
    digitalWrite (6, HIGH);
    digitalWrite (7, LOW);
    digitalWrite (8, HIGH);
    delay(1);
  }
  else if (number == 3)
  {
    digitalWrite (2, HIGH);
    digitalWrite (3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (6, LOW);
    digitalWrite (7, LOW);
    digitalWrite (8,  HIGH);
    delay(1);
  }
  else if (number == 4)
  {
    digitalWrite (2, LOW);
    digitalWrite (3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite (5, LOW);
    digitalWrite (6, LOW);
    digitalWrite (7, HIGH);
    digitalWrite (8, HIGH);
    delay(1);
  }
  else if (number == 5)
  {
    digitalWrite (2, HIGH);
    digitalWrite (3, LOW);
    digitalWrite (4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (6, LOW);
    digitalWrite (7, HIGH);
    digitalWrite (8, HIGH);
    delay(1);
  }
  else if (number == 6)
  {
    digitalWrite (2, HIGH);
    digitalWrite (3, LOW);
    digitalWrite (4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (6, HIGH);
    digitalWrite (7, HIGH);
    digitalWrite (8, HIGH);
    delay(1);
  }
  else if (number == 7)
  {
    digitalWrite (2, HIGH);
    digitalWrite (3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite (5, LOW);
    digitalWrite (6, LOW);
    digitalWrite (7, LOW);
    digitalWrite (8, LOW);
    delay(1);
  }
  else if (number == 8)
  {
    digitalWrite (2, HIGH);
    digitalWrite (3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (6, HIGH);
    digitalWrite (7, HIGH);
    digitalWrite (8, HIGH);
    delay(1);
  }
  else if (number == 9)
  {
    digitalWrite (2, HIGH);
    digitalWrite (3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (6, LOW);
    digitalWrite (7, HIGH);
    digitalWrite (8, HIGH);
    delay(1);
  }
}
void displayOff()
{
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

