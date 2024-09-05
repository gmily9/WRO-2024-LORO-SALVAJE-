//* Declaramos las variables */
long distancia;
long tiempo;
 
void setup() {
Serial.begin(9600);
/* Declaramos el pin 9 como salida del pulso ultrasonico */
pinMode(3, OUTPUT);
/* Declaramos el pin 8 como entrada (tiempo que tarda en volver) */
pinMode(2, INPUT);
/* Declaramos el pin 12 como el pin del LED */
pinMode(12, OUTPUT);
}
 
void loop() {
 
/* Se estabiliza el sensor */
digitalWrite(3, LOW);
delayMicroseconds(5);
/* Se envia el pulso ultrasonico */
digitalWrite(3, HIGH);
delayMicroseconds(10);
/* Mide el tiempo transcurrido entre la salida y la llegada del pulso ultrasonico */
tiempo = pulseIn(2, HIGH);
/* Se calcula la distancia en centimetros */
distancia = int(0.017*tiempo);
/* Si la distancia es menor a 15 centimetros encendemos el led */
if (distancia < 15) {
digitalWrite(12, HIGH);
}
/* Si la distancia es mayor a 15 centimetros, el led permanece apagado */
else {
digitalWrite(12, LOW);
}
/* Se imprime la distancia en centimetros en el monitor serial */
Serial.println("Distancia ");
Serial.println(distancia);
Serial.println(" cm");
}