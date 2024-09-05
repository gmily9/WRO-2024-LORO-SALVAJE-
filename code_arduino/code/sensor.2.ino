const int Trigger1 = 2; 
const int Echo1 = 3;

const int Trigger2 = 2; 
const int Echo2 = 3;

const int Trigger3 = 2; 
const int Echo3 = 3;
void setup() {

  pinMode(Trigger1, OUTPUT); 
  pinMode(Echo1, INPUT);  
  digitalWrite(Trigger1, LOW);

  pinMode(Trigger2, OUTPUT); 
  pinMode(Echo2, INPUT);  
  digitalWrite(Trigger2, LOW);

  
  pinMode(Trigger3, OUTPUT); 
  pinMode(Echo3, INPUT);  
  digitalWrite(Trigger3, LOW);

}

void loop() {
   medir_distancia(Trigger1, Echo1); 
  medir_distancia(Trigger2, Echo2); 
  medir_distancia(Trigger3, Echo3); 
}
void medir_distancia(const int trigger, const int echo){
  long t; 
  long d; 
 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);          
  digitalWrite(trigger, LOW);
  
  t = pulseIn(echo, HIGH); 
  d = t/59;             
  
  Serial.print("Distancia: ");
  Serial.print(d);     
  Serial.print("cm");
  Serial.println();
  delay(100); 
  return d;
  }


