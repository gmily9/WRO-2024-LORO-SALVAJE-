import RPi.GPIO as GPIO
import time
from sense_hat import SenseHat 

#aqui configuramos el sense hat
sense = SenseHat()

# aqui configuramos el servo
servo_pin = 17
GPIO.setmode(GPIO.BCM)
GPIO.setup(servo_pin, GPIO.OUT)

#aqui configuramos el motor con el lm298
inA = 18
in2 = 26
in1 = 4

GPIO.setup(inA, GPIO.OUT)
GPIO.setup(in1, GPIO.OUT)
GPIO.setup(in2, GPIO.OUT)

#servo = GPIO.PWM(servo_pin, 50)
#servo.start(0)

def leer_imu():
    orientation =sense.get_orientation()
    return orientation ['roll'], orientation['pitch'], orientation ['yaw']#gyro.x, gyro.y, gyro.z
        
def control_servo(angle):
    servo = GPIO.PWM(servo_pin,50)
    servo.start(0)
    dutycycle = 2.5 + (angle/180.0)*10 #dutycycle = 50.0 (angle/180.0)*100.0
    servo.ChangeDutyCycle(dutycycle)
    time.sleep(0.5)
        
def control_motor(speed):
    if speed > 0:
        GPIO.output(inA, GPIO.HIGH)
        GPIO.output(in1, GPIO.LOW)
        GPIO.output(in2, GPIO.HIGH)
    elif speed < 0:
        GPIO.output(inA, GPIO.HIGH)
        GPIO.output(in1, GPIO.LOW)
        GPIO.output(in2, GPIO.HIGH)
    else:
        GPIO.output(inA, GPIO.LOW)
        GPIO.output(in1, GPIO.LOW)
        GPIO.output(in2, GPIO.LOW)
    
servo_posicion_inicial = 86
control_servo(servo_posicion_inicial)

while True:
    roll, pitch, yaw =leer_imu()
    print(roll, pitch, yaw)
        
    desviacion = yaw - 0
        
    servo_angle =90 + desviacion * 10
    control_servo (servo_angle)
    
    motor_speed =50
    control_motor(motor_speed)
    
    time.sleep(0.1)
        


