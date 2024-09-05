
#include <AFMotor.h>
AF_DCMotor Motor3(3, MOTOR34_64KHZ);

void setup() 
{
  Motor3.setSpeed(250);
  //
}

void loop()
{
  Motor3.run(FORWARD);
  delay (5000);

  Motor3.run(BACKWARD);
  delay(5000);

 Motor3.run(RELEASE);
delay (2000);
}
