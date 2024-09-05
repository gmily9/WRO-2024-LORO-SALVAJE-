const int trigPin1 = 2;
const int echoPin1 = 3;


void setup() {
Serial.begin(9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);


}

void loop() {
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);

long duration = pulseIn(echoPin1, HIGH);

float distance = duration*0.034/2;




Serial.print("Distancia: ");
Serial.print(distance);
Serial.print("cm ");
delay(1000);

}
