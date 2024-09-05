// Definición de pines
const int trigPin = A0;  // Pin TRIG del sensor ultrasónico
const int echoPin = A1;  // Pin ECHO del sensor ultrasónico
const int motorPin1 = 2; // Pin IN1 del L298N
const int motorPin2 = 3; // Pin IN2 del L298N
const int enablePin = 4; // Pin ENA del L298N

void setup() {
  // Inicialización de pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT); // Configurar el pin de habilitación

  Serial.begin(9600); // Inicializa la comunicación serial
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

  // Control del motor
  if (distance > 5) {
    // Si la distancia es mayor a 5 cm, el motor avanza
    digitalWrite(motorPin1, HIGH); // IN1 HIGH
    digitalWrite(motorPin2, LOW);   // IN2 LOW
    digitalWrite(enablePin, HIGH);   // Habilitar el motor
  } else {
    // Si la distancia es 5 cm o menos, detener el motor
    digitalWrite(motorPin1, LOW);    // IN1 LOW
    digitalWrite(motorPin2, LOW);    // IN2 LOW
    digitalWrite(enablePin, LOW);     // Deshabilitar el motor
    delay(1000); // Esperar 1 segundo

    // Retroceder hasta que la distancia sea mayor a 20 cm
    while (distance <= 20) {
      digitalWrite(motorPin1, LOW);   // IN1 LOW
      digitalWrite(motorPin2, HIGH);  // IN2 HIGH
      digitalWrite(enablePin, HIGH);   // Habilitar el motor

      // Volver a medir la distancia
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.034 / 2;

      // Imprimir la distancia en el monitor serial
      Serial.print("Retrocediendo. Distancia: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
    // Detener el motor al salir del bucle
    digitalWrite(motorPin1, LOW);    // IN1 LOW
    digitalWrite(motorPin2, LOW);    // IN2 LOW
    digitalWrite(enablePin, LOW);     // Deshabilitar el motor
    delay(500);
  }

  delay(100); // Pequeña pausa para evitar lecturas demasiado rápidas
}
