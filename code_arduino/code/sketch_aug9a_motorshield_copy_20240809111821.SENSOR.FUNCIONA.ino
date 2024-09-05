#include <AFMotor.h>

 AF_DCMotor motor1(3);
 const int trigPin1 = A0;
 const int echoPin1 = A1;
 const int trigPin2 = A2;
 const int echoPin2 = A3;
 const int trigPin3 = A4;
 const int echoPin3 = A5;


void setup() {
  motor1.run(RELEASE);
  Serial.begin(9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);

}

void loop() {
 
   Serial.print("Sensor1 : ");
  
 Serial.print("cm");
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin1, LOW);
  long duration = pulseIn(echoPin1, HIGH);
  long distance = duration*0.034/2;
  Serial.println(distance);

    Serial.print("Sensor2 : ");
  
 Serial.print("cm");
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin2, LOW);
  long duration = pulseIn(echoPin2, HIGH);
  long distance = duration*0.034/2;
  Serial.println(distance);
 
  Serial.print("Sensor3 : ");
  
 Serial.print("cm");
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin3, LOW);
  long duration = pulseIn(echoPin3, HIGH);
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
 
