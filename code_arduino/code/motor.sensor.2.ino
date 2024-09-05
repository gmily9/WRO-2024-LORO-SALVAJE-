#include <L298N.h>

const unsigned int IN1 = 2;   // Pin IN1 del motor
const unsigned int IN2 = 3;   // Pin IN2 del motor
const unsigned int ENA = 4;   // Pin ENA del motor

const int trigPin = A0;       // Pin TRIG del sensor ultrasónico
const int echoPin = A1;       // Pin ECHO del sensor ultrasónico

// Crear una instancia del motor
L298N motor(ENA, IN1, IN2);

void setup() {
  // Inicialización de la comunicación serial
  Serial.begin(9600);
  
  // Esperar a que se abra el monitor serial
  while (!Serial) {
    // No hacer nada
  }

  // Configurar el pin del sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Establecer velocidad inicial
  motor.setSpeed(255);
}

void loop() {
  long duration, distance;

  // Enviar un pulso al sensor ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer el tiempo que tarda el pulso en volver
  duration = pulseIn(echoPin, HIGH);
  
  // Calcular la distancia en cm
  distance = duration * 0.034 / 2;

  // Imprimir la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control del motor basado en la distancia
  if (distance > 5) {
    // Si la distancia es mayor a 5 cm, el motor avanza
    motor.forward();
  } else {
    // Si la distancia es 5 cm o menos, detener el motor
    motor.stop();
    delay(1000); // Esperar 1 segundo

    // Retroceder hasta que la distancia sea mayor a 20 cm
    while (distance <= 20) {
      motor.backward();
      
      // Volver a medir la distancia
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.034 / 2;

      // Imprimir la distancia en el monitor serial
      Serial.print("Distancia: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
    // Detener el motor al salir del bucle
    motor.stop();
  }

  delay(100); // Pequeña pausa para evitar lecturas demasiado rápidas
}