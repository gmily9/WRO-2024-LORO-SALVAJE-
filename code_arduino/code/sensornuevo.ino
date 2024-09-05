#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor Motor3(3, MOTOR34_64KHZ);
Servo servoMotor;

const int trigPin1 = A0;
const int echoPin1 = A1;

const int trigPin2 = A2;
const int echoPin2 = A3;

void setup() {
  Serial.begin(9600);  // Agregado el punto y coma
  servoMotor.attach(A5); // Cambié A5 por 5, asegúrate de usar un pin digital

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  Motor3.setSpeed(250); // Mover esta línea después de la inicialización
}

void loop() {
  float distance1 = readDistance(trigPin1, echoPin1);
  float distance2 = readDistance(trigPin2, echoPin2);

  Serial.print("Sensor 1: ");
  Serial.print(distance1);
  Serial.print(" cm");

  Serial.print(" | Sensor 2: ");
  Serial.print(distance2);
  Serial.print(" cm");
  Serial.println(); // Agregado para mejorar la legibilidad

  delay(1000);

  if (distance1 < distance2) {
    servoMotor.write(60);
    Motor3.run(FORWARD); // Asegúrate de que FORWARD esté definido
    delay(3000);
  } else if (distance1 > distance2) {
    servoMotor.write(120);
    Motor3.run(FORWARD);
    delay(3000);
  } else {
    servoMotor.write(90);
    Motor3.run(FORWARD);
  }
}

float readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}