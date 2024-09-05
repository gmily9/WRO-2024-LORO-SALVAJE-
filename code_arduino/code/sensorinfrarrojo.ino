unsigned int referenciaBlanco = 100;
unsigned int referenciaSinSuperficie = 20;
unsigned int lecturaCNY70 = 0;

void setup() {
  Serial.begin(9600); //Configuracion de la velocidad serial

}

void loop() {
  lecturaCNY70 = analogRead(A0);

  if((lecturaCNY70 >= 0) && (lecturaCNY70 <= referenciaSinSuperficie )) {
    Serial.println("Sin Superficie");
  }
  else if((lecturaCNY70 > referenciaSinSuperficie) && (lecturaCNY70 < referenciaBlanco )) {
    Serial.println("Linea Negra");
    
  }
  else if(lecturaCNY70 >= referenciaBlanco){
    Serial.println("Superficie Blanca");
  }
  //Serial.print("Lectura: ");
  //Serial.println(lecturaCNY70); //Imprime el valor de la lectura del canal A0
  delay(1000); //retardo de 2 segundos entre lectura
}