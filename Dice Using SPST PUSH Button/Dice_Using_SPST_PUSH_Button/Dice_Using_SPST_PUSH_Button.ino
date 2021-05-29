void setup()
{
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, INPUT);
}
void loop()
{
  if(digitalRead(9)==LOW)
  {
    int RandomNumber=rand();
    RandomNumber=(RandomNumber%6)+1;
    if(RandomNumber==1)
    {
      one();   
    }
    else if(RandomNumber==2)
    {
      two();   
    }
    else if(RandomNumber==3)
    {
      three();   
    }
    else if(RandomNumber==4)
    {
      four();   
    }
    else if(RandomNumber==5)
    {
      five();  
    }
    else if(RandomNumber==6)
    {
      six();   
    }
  }
}
void one()     {
  digitalWrite (2, LOW);
  digitalWrite (3, HIGH);
  digitalWrite (4, HIGH);
  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
  digitalWrite (7, LOW);
  digitalWrite (8, LOW);
  delay(400) ;
}

void two()    {

  digitalWrite (2, HIGH) ;
  digitalWrite (3, HIGH) ;
  digitalWrite (4, LOW) ;
  digitalWrite (5, HIGH) ;
  digitalWrite (6, HIGH) ;
  digitalWrite (7, LOW) ;
  digitalWrite (8, HIGH) ;
  delay(400) ;
}


void three()
{
  digitalWrite (2, HIGH) ;
  digitalWrite (3, HIGH) ;
  digitalWrite (4, HIGH) ;
  digitalWrite (5, HIGH) ;
  digitalWrite (6, LOW) ;
  digitalWrite (7, LOW) ;
  digitalWrite (8,  HIGH) ;
  delay(400) ;
}


void four()
{
  digitalWrite (2, LOW) ;
  digitalWrite (3, HIGH) ;
  digitalWrite (4, HIGH) ;
  digitalWrite (5, LOW) ;
  digitalWrite (6, LOW) ;
  digitalWrite (7, HIGH) ;
  digitalWrite (8, HIGH) ;
  delay(400) ;
}

void five()  {
  digitalWrite (2, HIGH) ;
  digitalWrite (3, LOW) ;
  digitalWrite (4, HIGH) ;
  digitalWrite (5, HIGH) ;
  digitalWrite (6, LOW)  ;
  digitalWrite (7, HIGH) ;
  digitalWrite (8, HIGH) ;
  delay(400) ;
}
void six()  {
  digitalWrite (2, HIGH) ;
  digitalWrite (3, LOW) ;
  digitalWrite (4, HIGH) ;
  digitalWrite (5, HIGH) ;
  digitalWrite (6, HIGH) ;
  digitalWrite (7, HIGH) ;
  digitalWrite (8, HIGH) ;
  delay(400) ;
}
