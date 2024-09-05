#include <AFMotor.h>
AF_DCMotor motor1(1);

const int trigPin1 = A0;
const int echoPin1 = A1;
const int trigPin2 = A2;
const int echoPin2 = A3;
const int trigPin3 = A4;
const int echoPin3 = A5;

#define MAX_DISTANCE 200
#define OBSTACLE_DISTANCE 30
#define NORMAL_SPEED 250
#define SLOW_SPEED 125

const int sensorPin = 2; // Pin donde está conectado el sensor CNY70
const int ledPin = 13;   // Pin para indicar que el auto debe estacionarse

int contador = 0;         // Contador de líneas detectadas
bool lineaDetectada = false; // Estado de detección de línea

void setup() {
  pinMode(sensorPin, INPUT); // Configura el pin del sensor como entrada
    pinMode(ledPin, OUTPUT);    // Configura el pin del LED como salida
    Serial.begin(9600);         // Inicializa la comunicación serial

motor1.setSpeed(NORMAL_SPEED); // Establece la velocidad inicial del motor
  motor1.run(RELEASE); // Asegúrate de que el motor esté liberado inicialmente
  
  Serial.begin(9600);
  

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

long getDistance(int trigPin, int echoPin) {
  // Enviar pulso de trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer pulso de echo
  long duration = pulseIn(echoPin, HIGH);
  
  // Calcular distancia en centímetros
  long distance = (duration / 2) / 29.1;
  return distance;
}

void loop() {

  long distance1 = getDistance(trigPin1, echoPin1);
  long distance2 = getDistance(trigPin2, echoPin2);
  long distance3 = getDistance(trigPin3, echoPin3);

  Serial.print("Distancia 1: ");
  Serial.print(distance1);
  Serial.print(" cm, Distancia 2: ");
  Serial.print(distance2);
  Serial.print(" cm, Distancia 3: ");
  Serial.print(distance3);
  Serial.println(" cm");

  if (distance3 < OBSTACLE_DISTANCE) {
    // Detener el motor completamente
    motor1.setSpeed(0);
    motor1.run(RELEASE);
    Serial.println("Motor detenido: obstáculo detectado por el sensor 2.");
  } else if (distance1 < OBSTACLE_DISTANCE || distance2 < OBSTACLE_DISTANCE) {
    // Disminuir la velocidad del motor
    motor1.setSpeed(SLOW_SPEED);
    motor1.run(FORWARD); // O cualquier dirección, adelante
    Serial.println("Velocidad reducida: obstáculo detectado por sensor 1 o 3.");
  } else {
    // Mantener la velocidad normal
    motor1.setSpeed(NORMAL_SPEED);
    motor1.run(FORWARD); // O cualquier dirección, adelante
    Serial.println("Motor en movimiento a velocidad normal.");
  }

  delay(1000); // Esperar un momento antes de la siguiente lectura

  int sensorValue = digitalRead(sensorPin);
    
    // Si el sensor detecta la línea (asumiendo que LOW indica detección)
    if (sensorValue == LOW && !lineaDetectada) {
        lineaDetectada = true; // Se ha detectado una línea
        contador++; // Incrementa el contador
        Serial.print("Línea detectada. Contador: ");
        Serial.println(contador);
        
        // Si se han detectado 4 líneas
        if (contador >= 4) {
            Serial.println("Se han detectado 4 líneas. El auto se estacionará.");
            digitalWrite(ledPin, HIGH); // Enciende el LED para indicar estacionamiento
            // Aquí puedes agregar el código para que el auto se estacione
            // Por ejemplo, detener el motor o activar un sistema de estacionamiento
        }
    }
    
    // Si no se detecta la línea, restablece el estado
    if (sensorValue == HIGH) {
        lineaDetectada = false; // Resetea la detección
    }
    
    delay(100); // Pequeña pausa para evitar lecturas erráticas
}

