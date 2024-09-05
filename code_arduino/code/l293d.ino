#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Crear una instancia del Motor Shield
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Crear instancias de los motores
Adafruit_DCMotor *motorDir = AFMS.getMotor(4); // Motor de dirección (M3)
Adafruit_DCMotor *motorTra = AFMS.getMotor(3); // Motor de tracción (M4)

void setup() {
  Serial.begin(9600);           // Inicializa la comunicación serial
  Serial.println("Iniciando...");

  AFMS.begin();                 // Inicia el Motor Shield

  // Configura los motores
  motorDir->setSpeed(150);      // Velocidad del motor de dirección
  motorTra->setSpeed(255);      // Velocidad del motor de tracción

  // Prueba el motor de dirección
  Serial.println("Probando motor de dirección...");
  motorDir->run(FORWARD);       // Gira a la dirección deseada
  delay(2000);                  // Mantiene el giro por 2 segundos
  motorDir->run(RELEASE);       // Detiene el motor
  delay(1000);                  // Espera 1 segundo

  // Prueba el motor de tracción
  Serial.println("Probando motor de tracción...");
  motorTra->run(FORWARD);       // Mueve el motor de tracción hacia adelante
  delay(2000);                  // Mantiene el movimiento por 2 segundos
  motorTra->run(RELEASE);       // Detiene el motor
}

void loop() {
  // No hay nada en el loop para esta prueba
}