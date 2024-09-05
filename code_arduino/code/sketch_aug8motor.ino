const int pinENA = 8;
const int pinIN1 = 9;
const int pinIN2 = 10;

const int speed = 200;    

void setup()
{
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinENA, OUTPUT);
}

void loop()
{
  
  digitalWrite(pinIN1, HIGH);
  digitalWrite(pinIN2, LOW);
  analogWrite(pinENA, speed);
  delay(3000);
}