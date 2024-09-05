const int PinIN1 = 2;
const int PinIN2 = 4;

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

  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  Serial.begin(9600);

}

void loop() {

  int speed = 150;
  int t = 1000;

  
  delay(2000);
  

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
