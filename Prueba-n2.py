from sense_hat import SenseHat
import time
import RPi.GPIO as GPIO
import threading
from ultrasonicos import ultrasonico
from 
sense = SenseHat()

servo_pin = 17 #integers entero
IN1 = 22  # Pin GPIO para dirección 1
IN2 = 4  # Pin GPIO para dirección 2
EN = 18 # pin GPIO para controlar la velocidad

GPIO.setmode(GPIO.BCM)
sensor_left = ultrasonico

# Establece el modo de numeración de pines (BCM o BOARD)
GPIO.setup(IN1, GPIO.OUT)
GPIO.setup(IN2, GPIO.OUT)
GPIO.setup(EN, GPIO.OUT)

GPIO.setup(servo_pin, GPIO.OUT)
sensor_front = ultrasonico(27, 5)
sensor_left = ultrasonico(6, 12)
sensor_right = ultrasonico(13, 19)
GPIO.setwarnings(False)

# PWM: modulador de ancho de pulsos
PWM = GPIO.PWM(EN, 50)
PWM.start(0)
pwm = GPIO.PWM(servo_pin,50)
pwm.start(0)

sense.set_imu_config(False, True, True)

#yaw_offset = sense.get_orientation()["yaw"]
kp = 0.5
orientacion = 0
esquina = False
sensor = sensor_left
GPIO.setwarnings(False)
      
def avanzar():
    GPIO.output(IN1, GPIO.HIGH)
    GPIO.output(IN2, GPIO.LOW)
    GPIO.output(EN, GPIO.HIGH)
def atras():
    GPIO.output(IN1, GPIO.LOW)
    GPIO.Output(IN2, GPIO.HIGH)
    pwm.ChangeDutyCycle()
    detener()
    
def detener():
    GPIO.output(IN1, GPIO.LOW)
    GPIO.output(IN2, GPIO.LOW)
    pwm.ChangeDutyCycle(0)
    
def orientacion_imu_ini():
    orientation = sense.get_orientation()
    yaw = int(orientation["yaw"])
    return yaw

def angulo_a_duty_cycle(angulo):
    return 2.5 + (angulo/180.0)*10

def mover_servo(angulo):
    duty_cycle = angulo_a_duty_cycle(angulo)
    pwm.ChangeDutyCycle(duty_cycle)

def girar():
    global orientacion, esquina_doblado, esquina_detectada
    orientacion += -89.5 if sensor == sensor_left else 89.5
    orientacion %= 360
    estabilizar(orientacion)
    esquina = True
    time.sleep(0.1)
    
def elegir_sensor():
    distancia_izquierda = sensor_left.medir_distancia()
    distancia_derecha = sensor_right.medir_distancia()
    return sensor_right if distancia_izquierda > distancia_derecha else sensor_left    

def motor_adelante(speed):
    if 0 <= speed <= 100:
        PWM.ChangeDutyCycle(speed)
        GPIO.output(IN1, GPIO.HIGH)
        GPIO.output(IN2, GPIO.LOW)
        
def estabilizar(angulo_deseado):
    angulo_actual = sense.get_orientation()["yaw"]
    error = angulo_deseado - angulo_actual
    if error > 180:
        error -= 360
    elif error < -180:
        error += 360
    señal_control = kp * error
    señal_control = 83 - señal_control
    señal_control = max(40, min(120, señal_control))
    mover_servo(señal_control)
    time.sleep(2)
    
    
detener()
estabilizar(orientacion)
time.sleep(2)

"""
while True:
    motor_adelante(60)
    estabilizar(orientacion)
    distancia_frontal = sensor_front.medir_distancia()
    if distancia_frontal <= 30:
        detener()
        sensor = elegir_sensor()
        break
"""
while True:
    
        estabilizar(orientacion)
        distancia = sensor.medir_distancia()
        if distancia > 150 and not esquina:
            girar()
        if distancia <= 150:
            esquina = False
        
        motor_adelante(60)
        
        time.sleep(0.1)
        
       
            
        

