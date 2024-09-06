# WRO-2024-LORO-SALVAJE-
Toda la información del equipo "Loro Salvaje" en la WRO 2024
Breve resumen:
La Olimpiada Mundial de Robots que se llevó a cabo en Salta representó una oportunidad valiosa para aplicar nuestros consejos teóricos en la práctica. Nos inscribimos con la expectativa de enriquecer nuestros conocidos, ya que este evento contiene con la participación de varios equipos de la provincia.

Conformamos el equipo de trabajo según lo exigido por el rigimen, compuesto por tres estudiantes y un docente orientador. Desde el mes de junio, trabajos arduamente para acumlir con la planificación realizada y llegar a condiciones a la competencia.

Comenzamos fabricando el chasis utilizando materiales de nuestra institución, como lugares de metal y plástico, ajustando a las especificaciones de peso y altas sugerencias por la organización del evento. Posteriormente, iniciamos el ensamblaje de la parte mecánica, diseño, ajustando e instalando el motor para proporcionar movimiento autónomo y el servo para la dirección del vehículo.

En cuanto a la programación, utiliza inicialmente Arduino NANO con Minibloq (Diagrama de bloques). Sin embargo, a medida que avanzábamos en el proyecto, nos dimos cuenta de que este sistema era limitado debido a la falta de lugares de conexión necesarios para nuestros objetivos de autonomía y dirección. Decidimos reemplazarlo por una placa Arduino UNO, que también resultó ser limitada. Finalmente, optamos por la Raspberry Pi 3 y utilizamos Python para la programación. Este es el sistema con el que participamos en la competencia y que seguimos mejorando hasta el día de hoy.

En este repositorio se encuentran todos los datos e información sobre nuestro auto autónomo, desarrollado por el equipo “Loros Salvajes” (denominado así en honor a la mascota de nuestra institución).

Usamos diversos materiales, entre los que se encuentran:

3 sensores ultrasónicos
Motor CC
servo
Escudo de motor L298N
Frambuesa Pi 3
Bateria Lipo 2200mA
Bateria PCBOX 20000mA
Sombrero sensorial (giroscopio)
Cables unifilares
Inglés
Placas de metal y plástico


Aquí tienes el texto corregido y ajustado para mayor claridad y precisión en el informe:

**CONSTRUCCIÓN Y PELÍCULA**
Para el diseño del chasis del robot, usos un kit de robótica proporcionado por la empresa RobotGroup, que estaba disponible en nuestra institución. Este kit contiene diversos componentes, entre ellos lugares de plástico y metal, que ensamblamos utilizando tornillos también suministrados por la institución.

El chasis tiene unas dimensiones totales de 25 x 18,5 cm y una altura de 17,5 cm. La elección de estos componentes tuvo como objetivo reducir costos y aprobar equipos que apenas se utilizaban, dado que nuestra institución tenía una orientación "electromecánica". Por esta razón, toda la programación aprendida durante el proceso fue autodidacta.

El vehículo está equipado con dos motores para proporcionar potencia. El primero es el motor de tracción, un motor DC, que a viajes de un sistema de engranajes simple, transmite potencia al eje de las ruedas traseras. Este motor está fijado al chasis con tornillos, al igual que el eje del motor, que está sujeto al engranaje conductor. El segundo motor es el de dirección, un servomotor Futaba S3003, ubicado en la parte semi-delantera del auto. Este servomotor está asegurado al chasis y al je de las ruedas delanteras con tornillos y está montado en el centro del eje para garantizar un movimiento equilibrado en ambos lados.

Los sensores ultrasónicos están distribuidos a lo largo del chasis. Utilizamos tres sensores HC-SR04, colocados dos en cada lateral y uno adicional en la parte frontal del chasis. También hemos instalado un controlador L298N en la parte superior trasera del chasis, junto con un regulador de voltaje LM2596 conectado a una batería PCBOX.

La Frambuesa Pi 3 está montada encima del servomotor y asegurada con tornillos. La cámara Raspberry Pi Rev. 1.3 se encuentra en la parte superior de la chasis, a una alta adecuada para detectar los obstáculos.

Para las ruedas, inicialmente utilizando ruedas procedimientos de un auto de juguete en el primer modelo. Sin embargo, decisiones cambiar a las ruedas Robobloq debido a que las primeras eran demasiado blandas, lo que causaba desestabilización en el robot y limitaba el movimiento de dirección. Las ruedas Robobloq, siendo más firmas, proporcionan una mayor estabilidad y mejoran el control del movimiento.

Es importante destacar que las ruedas están aseguradas con tornillos para evitar cualquier juego y asegurar que no se desacoplen del robot durante su operación.

En el centro de las ruedas traseras, conectores un eje de metal ensamblado a un engranaje conducido. Este eje, que proviene de un auto de juguete, se acopla al sistema de engranajes, permiso que las ruedas giren en sincronía con el motor.

Para las ruedas delanteras, constructimos un tipo de equipo utilizando lugares reciclados de carreras de netbooks. Este eje está compuesto por tres plazas: una acoplada al servomotor y otras dos paralelas que sirve de soporte para el eje vertical de las ruedas. La placa conectada al servomotor transmite la potencia del servomotor a las ruedas, mientras que las otras dos placas proporcionales estabilidad adicional al sistema.

En la construcción, tanto empleamos nuevos "separadores de goma" para separar las piezas y estabilizarlas. Estos separados ayudan a evitar el contacto directo entre los componentes, reduciendo el riesgo de desgaste y contribuyendo a una mayor estabilidad general del robot.

**Gestión de Obstáculos**
Inicialmente, aviones utilizados los sensores ultrasónicos para mantener el robot centrado en la pista. La idea era que, al detectar un obstáculo, los sensores determinaran la dirección a tomar según el espacio disponible en cada lado. Si un sensor detectaba un obstáculo más cerca, el robot gira el lado donde el espacio era mayor, permiso una navegación eficiente y evitando colisiones.

El sistema de gesción de obstáculos se basa en los sensores ultrasónicos para guiar el movimiento del robot y evitar colisiones. La lógica operativa es la señor:

-Condiciones Iniciales: Mientras el sensor frontal (S0) detecta una distancia mayor a 20 cm, el servomotor está posicionado a 90° y el motor avanza. Si se detecta una desviación hacia un costado, cada sensor lateral (S1 y S2) medirá la distancia y comparará con la distancia inicial. El servomotor ajustará su ángulo para centrar el robot nuevo, dependiente del sensor detectará una diferencia mayor.

-Evasión de Obstáculos: Si el sensor frontal (S0) detecta una distancia menor a 20 cm, los sensores laterales (S1 y S2) mediran la distancia en sus respectivos lados y enviaran señores para ajustar el ángulo del servomotor, con el objetivo de evitar el obstáculo y seguir el camino más libre.

-Detección de Obstáculos Cercanos: Si el sensor frontal (S0) detecta una distancia menor a 5 cm, el motor se detiene durante un segundo y luego retrocede para retomar la ruta adaptada.

-Conteo de Vueltas: Se implementó un conteo para monitorear las clases de ajuste del servomotor. Cada vez que un sensor entorno una señor para cambiar el dentrogulo del servomotor, se cuenta. Cuando un sensor entorno esta señor 4 veces, se considera que el robot ha dado una vuelta completa. Esto permite al robot detenerse en el punto deseado del recorrido.

No obstante, se identificaron algunas fallas en esta lógica, lo que llegó a la implementación de una cámara para la detección de obstáculos bajos en colores. Se realizaron ajustes en la luzica del sistema para mejorar la precisión y la eficacia en la navegación.

**Programación**
Comenzamos definidos los objetivos de funcionamiento del robot y enfocándonos en aprender sobre programación para iniciar el proyecto. El proceso de programación se desarrolló en varias etapas:

-Presentación con RoboBloq: Inicialmente, utilizamos RoboBloq, un sistema de programación basado en bloques, para familiarizarnos con las lógicas básicas. Realizamos tareas simples como hacer que el robot avanzara y retrocediera, y posteriormente amigos complejidad con movimientos en ángulos, giros, paradas y avances.

-Avance con miniBloq: Posteriormente, empleamos miniBloq, un lenguaje de bloques más avanzado, que nos permitió mejorar la programación de sensores, servomotores y motores. Comenzamos con ejercicios sencillos y, progresivamente, aumentamos la dificultad para adaptar el robot a tareas más complejas.

-Desarrollo con Arduino: Una continuación, trabajos con Arduino, integrado codigos simples y luego combinandolos para desarrollar funciones más completas. Utilizamos bibliotecarios y recursos en línea para superar los descubrimientos y optimizar la programación.

**-Implementación con Raspberry Pi 3: Debido a las limitaciones de Arduino, decidimos incorporar una Raspberry Pi 3 y utilizar Python para la programación. Aunque el proceso fue desafiante, logramas desarrollar varias lógicas, empezando con codedos básicos y luego combinando

**Vídeo de YouTube**
https://youtu.be/D18wJvHwUlM?si=ip-v9uGFT2Nh8hsJ

![Subiendo IMG_20240817_210501436_HDR_AE.jpg...]()
![Subiendo 20240905_105054.jpg...]()
