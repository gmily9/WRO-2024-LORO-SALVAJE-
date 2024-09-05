#include <AFMotor.h>

const int trigPin1 = A0;
const int echoPin1 = A1;

const int trigPin2 = A2;
const int echoPin2 = A3;

const int trigPin3 = A4;
const int echoPin3 = A5;

AF_DCMotor motor(1);

void setup() {
  Serial.begin(9600);
  motor.setSpeed(255);//Velocidad de 0 a 255
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
 

}

void loop() {
 float distance1 = readDistance(trigPin1, echoPin1);
 float distance2 = readDistance(trigPin2, echoPin2);
 float distance3 = readDistance(trigPin3, echoPin3);

 if(Serial.available()>0){
    char command = Serial.read();
    if(command == 'F'){
      motor.run(BACKWARD);
      delay(3000);
    }
    if(command == 'S'){
      motor.run(RELEASE);
      delay(3000);
    }
  }
 
 
 Serial.println(distance3);
  delay(200);
}

float readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034/2;
  }