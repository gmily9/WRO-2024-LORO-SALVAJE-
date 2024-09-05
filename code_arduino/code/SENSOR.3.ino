const int trigPin1 = A0;
const int echoPin1 = A1;

const int trigPin2 = A2;
const int echoPin2 = A3;

const int trigPin3 = A4;
const int echoPin3 = A5;

void setup() {
  Serial.begin(9600);
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
 
 Serial.print("Sensor 1: ");
 Serial.print(distance1);
 Serial.print("cm");

  Serial.print("Sensor 2: ");
 Serial.print(distance2);
 Serial.print("cm");

  Serial.print("Sensor 3: ");
 Serial.print(distance3);
 Serial.print("cm");
  delay(1000);
}

float readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034/2;
  return distance;
}

