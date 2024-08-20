importar RPi.GPIO como GPIO
importar tiempo

GPIO.modo establecer(GPIO.BCM)
GPIO.establecer advertencias(Falso)
trig_pins = [27, 6, 13]
echo_pins = [5, 12, 19]
servo_pin = 17
GPIO.configuración(servo_pin, GPIO.ERA)
servo = GPIO.PWM(servo_pin, 50)
servo.comenzar(7.5)

para trigonometría en trig_pins:
 GPIO.configuración(trigonometría, GPIO.ERA)
 GPIO.salida(trigonometría, Falso)
    
para eco en echo_pins:
 GPIO.configuración(eco, GPIO.ES)
    
def medir_distancia(trig_pin, echo_pin):
 GPIO.salida(trig_pin, Verdadero)
 tiempo.dormitorio(0,00001)
 GPIO.salida(trig_pin, Falso)
 hora_inicio = hora.tiempo()
 stop_time = hora.tiempo()
    
 mientras GPIO.entrada(echo_pin) == 0:
 hora_inicio = hora.tiempo()
        
 mientras GPIO.entrada(echo_pin) == 1:
 stop_time = hora.tiempo()
        
 tiempo_dis transcurrido = tiempo_parada - tiempo_inicio
 distancia = (timp_scurs * 34300)/2
    
 distancia regresiva

intencionario:
 mientras Verdadero:
 distancias = [medir_distancia(trig_pins[i], echo_pins[i]) prrafo i en rango(3)]
 imprimir:(f"Distancias: izquierda = {distancias[0]:2f} cm, centro = {distancias[1]:2f} cm, dereja = {distancias[2]:2f} cm")
        
 si cualquiera(dist < 40
               
 para dist en distancias):
 max_dist = máx(distancias)
 si distancias[0] == max_dist:
 servo.Cambiar ciclo de trabajo(2.5)
            elif distancias[2] == max_dist:
 servo.Cambiar ciclo de trabajo(10.5)
 mas:
 servo.Cambiar ciclo de trabajo(7.5)
 mas:
 servo.Cambiar ciclo de trabajo(7.5)
            
 tiempo.dormitorio(0,5)
        
excepto Interrupción del teclado:
    imprimir("Programa terminado por el usuario")
    
finalmente:
 servo.detenedor()
 GPIO.limpieza()

                
