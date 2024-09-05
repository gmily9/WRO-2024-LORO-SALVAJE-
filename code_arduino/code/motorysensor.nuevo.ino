#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor Motor3(3, MOTOR34_64KHZ);
Servo servoMotor;

void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial
  servoMotor.attach(A5); // Conecta el servomotor al pin A5
  Motor3.setSpeed(250); // Establece la velocidad del motor
}

void loop() {
  Motor3.run(FORWARD);  // Hace que el motor avance
  servoMotor.write(90);  // Mueve el servo a 90 grados
  delay(3000);           // Espera 3 segundos
  
  servoMotor.write(35);  // Mueve el servo a 45 grados
  delay(3000);           // Espera 3 segundos

  servoMotor.write(90);  // Mueve el servo a 90 grados
  delay(3000);  
  
  servoMotor.write(145); // Mueve el servo a 135 grados
  delay(3000);           // Espera 3 segundos
  
  servoMotor.write(90);  // Mueve el servo a 90 grados
  Motor3.run(RELEASE);   // Detiene el motor
  delay(2000);           // Espera 2 segundos
}