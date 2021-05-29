char Character;
void setup()
{
  Serial.begin(9600);
  for (int i = 2; i <= 9; i++)
  {
    pinMode (i, OUTPUT);
  }
  //Pin 2-8 Will be dedicated for 7 Segment
  //Pin 9-12 will be dedicated for switching button for 7SEG-MPX4-CA
  //          ......                 ......                  ......                 ......
  //          . 12 .                 . 11 .                  . 10 .                 .  9 .
  //          ......                 ......                  ......                 ......
  //           OFF                    OFF                     OFF                     ON
}

void loop()
{
  if (Serial.available() > 0)
  {
    Character = Serial.read();
    if (Character >= '0' && Character <= '9')
    {
      displayOff();
      digitalWrite(9, HIGH);
      onNumber(Character-'0');

      Serial.print("Number received: ");
      Serial.println(Character);
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
}

