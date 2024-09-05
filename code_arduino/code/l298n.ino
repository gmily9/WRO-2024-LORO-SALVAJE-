#include <L298N.h>


const unsigned int IN3 = 4;
const unsigned int IN4 = 2;
const unsigned int ENB = 3;

// Create one motor instance
L298N motor(ENB, IN3, IN4);

void setup()
{
  // Used to display information
  Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }

  // Set initial speed
  motor.setSpeed(255);
}

void loop()
{

  // Tell the motor to go forward (may depend by your wiring)
  motor.forward();

  // Alternative method:
  // motor.run(L298N::FORWARD);

  //print the motor status in the serial monitor
  printSomeInfo();

  delay(3000);

  // Stop
  motor.stop();

  // Alternative method:
  // motor.run(L298N::STOP);

  printSomeInfo();

  // Change speed
  motor.setSpeed(255);

  delay(3000);

  // Tell the motor to go back (may depend by your wiring)
  motor.backward();

  // Alternative method:
  // motor.run(L298N::BACKWARD);

  printSomeInfo();

  motor.setSpeed(120);

  delay(3000);

  // Stop
  motor.stop();

  printSomeInfo();

  delay(3000);
}

/*
Print some informations in Serial Monitor
*/
void printSomeInfo()
{
  Serial.print("Motor is moving = ");
  Serial.print(motor.isMoving());
  Serial.print(" at speed = ");
  Serial.println(motor.getSpeed());
}
