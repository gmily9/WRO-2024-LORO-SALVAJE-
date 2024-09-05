#include <AFMotor.h>

 AF_DCMotor motor1(1);
 const int trigPin = A0;
 const int echoPin = A1;


void setup() {
  motor1.run(RELEASE);
  Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration*0.034/2;
  Serial.println(distance);

  motor1.run(FORWARD);
  delay(5000);
  motor1.setSpeed(250);
  motor1.run(BACKWARD);
  delay(5000);

if(distance>30){
  motor1.run(FORWARD);
  delay(5000);
  motor1.setSpeed(250);
  motor1.run(BACKWARD);
  delay(5000);
} else{
  motor1.run(RELEASE);
  delay(50000);
}

}
