#include <Servo.h>

// Definición de pines para los sensores ultrasónicos
const int trig1Pin = A0;  // Pin TRIG del sensor frontal
const int echo1Pin = A1;  // Pin ECHO del sensor frontal
const int trig2Pin = A2;  // Pin TRIG del sensor lateral derecho
const int echo2Pin = A3;  // Pin ECHO del sensor lateral derecho
const int trig3Pin = A4;  // Pin TRIG del sensor lateral izquierdo
const int echo3Pin = A5;  // Pin ECHO del sensor lateral izquierdo

const int motorPin = 9;   // Pin de control del motor DC
const int servoPin = 10;  // Pin de control del servo S3003

const int senrThreshold = 30; // Umbral de distancia en cm

Servo myServo;
int motorSpeed = 255; // Velocidad máxima del motor

void setup() {
  myServo.attach(servoPin);
  pinMode(motorPin, OUTPUT);
  pinMode(trig1Pin, OUTPUT);
  pinMode(echo1Pin, INPUT);
  pinMode(trig2Pin, OUTPUT);
  pinMode(echo2Pin, INPUT);
  pinMode(trig3Pin, OUTPUT);
  pinMode(echo3Pin, INPUT);
  myServo.write(90); // Establece el servo en la posición inicial
}

void loop() {
  float distance1 = getDistance(trig1Pin, echo1Pin);
  float distance2 = getDistance(trig2Pin, echo2Pin);
  float distance3 = getDistance(trig3Pin, echo3Pin);

  if (distance1 > sensorThreshold) {
    // Caso cuando el sensor frontal detecta más de 30 cm
    analogWrite(motorPin, motorSpeed); // Motor a velocidad normal

    if (distance2 < distance3) {
      // Menos espacio en la derecha
      myServo.write(110); // Dobla a la derecha
      delay(300); // Espera mientras el coche gira
    } else if (distance3 < distance2) {
      // Menos espacio en la izquierda
      myServo.write(70); // Dobla a la izquierda
      delay(300); // Espera mientras el coche gira
    } else {
      myServo.write(90); // Mantén el rumbo recto
    }
    delay(500); // Espera antes de tomar la siguiente acción
  } else {
    // Caso cuando el sensor frontal detecta menos de 30 cm
    if (distance2 > distance3) {
      myServo.write(45); // Doblado a la izquierda
    } else {
      myServo.write(135); // Doblado a la derecha
    }
    analogWrite(motorPin, motorSpeed / 2); // Reduce la velocidad del motor
    delay(300); // Espera mientras el coche gira
    // Espera hasta que el sensor frontal detecte más de 30 cm
    while (getDistance(trig1Pin, echo1Pin) <= sensorThreshold) {
      delay(100); // Espera 100 ms
    }
    myServo.write(90); // Vuelve a la posición inicial
    analogWrite(motorPin, motorSpeed); // Restaura la velocidad normal
  }
}

// Función para medir la distancia utilizando el sensor ultrasónico
float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration / 2.0) * 0.0344; // Distancia en cm
  
  return distance;
}

