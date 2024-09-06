![20240905_105054](https://github.com/user-attachments/assets/b28c8818-1957-4613-b204-41e9ee13ed35)![IMG_20240817_210501436_HDR_AE](https://github.com/user-attachments/assets/cffe2ac8-6e65-4508-b61e-24e2332bcafa)# WRO-2024-LORO-SALVAJE-
Toda la información del equipo "Loro Salvaje" en la WRO 2024
Breve resumen:
La World Robot Olympiad que se llevó a cabo en Salta representó una valiosa oportunidad para aplicar nuestros conocimientos teóricos en la práctica. Nos inscribimos con la expectativa de enriquecer nuestros conocimientos, ya que este evento contaba con la participación de varios equipos de la provincia.

Conformamos el equipo de trabajo según lo exigido por el reglamento, compuesto por tres estudiantes y un docente orientador. Desde el mes de junio, trabajamos arduamente para cumplir con la planificación realizada y llegar en condiciones óptimas a la competencia.

Comenzamos fabricando el chasis utilizando materiales de nuestra institución, como placas de metal y plástico, ajustándolo a las especificaciones de peso y altura sugeridas por la organización del evento. Posteriormente, iniciamos el ensamblaje de la parte mecánica, diseñando, ajustando e instalando el motor para proporcionar movimiento autónomo y el servo para la dirección del vehículo.

En cuanto a la programación, inicialmente utilizamos Arduino NANO con Minibloq (Diagrama de bloques). Sin embargo, a medida que avanzábamos en el proyecto, nos dimos cuenta de que este sistema era limitado debido a la falta de puertos de conexión necesarios para nuestros objetivos de autonomía y dirección. Decidimos reemplazarlo por una placa Arduino UNO, que también resultó ser limitada. Finalmente, optamos por la Raspberry Pi 3 y utilizamos Python para la programación. Este es el sistema con el que participamos en la competencia y que seguimos mejorando hasta el día de hoy.

En este repositorio se encuentran todos los datos e información sobre nuestro auto autónomo, desarrollado por el equipo “Loros Salvajes” (denominado así en honor a la mascota de nuestra institución).

Usamos diversos materiales, entre los que se encuentran:

3 sensores ultrasónicos
Motor DC
Servo
Motor Shield L298N
Raspberry Pi 3
Batería Lipo 2200mA
Batería PCBOX 20000mA
SenseHat (giroscopio)
Cables unifilares
Engranajes
Placas de metal y plástico


Aquí tienes el texto corregido y ajustado para mayor claridad y precisión en el informe:

**CONSTRUCCIÓN y MOVILIDAD**
Para el diseño del chasis del robot, utilizamos un kit de robótica proporcionado por la empresa RobotGroup, que estaba disponible en nuestra institución. Este kit contenía diversos componentes, entre ellos placas de plástico y metal, que ensamblamos utilizando tornillos también suministrados por la institución.

El chasis tiene unas dimensiones totales de 25 x 18.5 cm y una altura de 17.5 cm. La elección de estos componentes tuvo como objetivo reducir costos y aprovechar equipos que apenas se utilizaban, dado que nuestra institución tiene una orientación "electromecánica". Por esta razón, toda la programación aprendida durante el proceso fue autodidacta.

El vehículo está equipado con dos motores para proporcionar potencia. El primero es el motor de tracción, un motor DC, que a través de un sistema de engranajes simple, transmite potencia al eje de las ruedas traseras. Este motor está fijado al chasis con tornillos, al igual que el eje del motor, que está sujeto al engranaje conductor. El segundo motor es el de dirección, un servomotor Futaba S3003, ubicado en la parte semi-delantera del auto. Este servomotor está asegurado al chasis y al eje de las ruedas delanteras con tornillos y está montado en el centro del eje para garantizar un movimiento equilibrado en ambos lados.

Los sensores ultrasónicos están distribuidos a lo largo del chasis. Utilizamos tres sensores HC-SR04, colocados dos en cada lateral y uno adicional en la parte frontal del chasis. También hemos instalado un controlador L298N en la parte superior trasera del chasis, junto con un regulador de voltaje LM2596 conectado a una batería PCBOX.

La Raspberry Pi 3 está montada encima del servomotor y asegurada con tornillos. La cámara Raspberry Pi Camera Rev. 1.3 se encuentra en la parte superior delantera del chasis, a una altura adecuada para detectar los obstáculos.

Para las ruedas, inicialmente utilizamos ruedas provenientes de un auto de juguete en el primer modelo. Sin embargo, decidimos cambiar a las ruedas Robobloq debido a que las primeras eran demasiado blandas, lo que causaba desestabilización en el robot y limitaba el movimiento de dirección. Las ruedas Robobloq, siendo más firmes, proporcionan una mayor estabilidad y mejoran el control del movimiento.

Es importante destacar que las ruedas están aseguradas con tornillos para evitar cualquier juego y asegurar que no se desacoplen del robot durante su operación.

En el centro de las ruedas traseras, conectamos un eje de metal ensamblado a un engranaje conducido. Este eje, que proviene de un auto de juguete, se acopla al sistema de engranajes, permitiendo que las ruedas giren en sincronía con el motor.

Para las ruedas delanteras, construimos un tipo de eje utilizando plásticos reciclados de carcasas de netbooks. Este eje está compuesto por tres placas: una acoplada al servomotor y otras dos paralelas que sirven de soporte para el eje vertical de las ruedas. La placa conectada al servomotor transmite la potencia del servomotor a las ruedas, mientras que las otras dos placas proporcionan estabilidad adicional al sistema.

En la construcción, también empleamos numerosos "separadores de goma" para separar las piezas y estabilizarlas. Estos separadores ayudan a evitar el contacto directo entre los componentes, reduciendo el riesgo de desgaste y contribuyendo a una mayor estabilidad general del robot.

**Gestión de Obstáculos**
Inicialmente, planeábamos utilizar los sensores ultrasónicos para mantener el robot centrado en la pista. La idea era que, al detectar un obstáculo, los sensores determinaran la dirección a tomar según el espacio disponible en cada lado. Si un sensor detectaba un obstáculo más cerca, el robot giraría hacia el lado donde el espacio era mayor, permitiendo una navegación eficiente y evitando colisiones.

El sistema de gestión de obstáculos se basa en los sensores ultrasónicos para guiar el movimiento del robot y evitar colisiones. La lógica operativa es la siguiente:

-Condiciones Iniciales: Mientras el sensor frontal (S0) detecte una distancia mayor a 20 cm, el servomotor estará posicionado a 90° y el motor avanzará. Si se detecta una desviación hacia un costado, cada sensor lateral (S1 y S2) medirá la distancia y comparará con la distancia inicial. El servomotor ajustará su ángulo para centrar el robot nuevamente, dependiendo de cuál sensor detecte una diferencia mayor.

-Evasión de Obstáculos: Si el sensor frontal (S0) detecta una distancia menor a 20 cm, los sensores laterales (S1 y S2) medirán la distancia en sus respectivos lados y enviarán señales para ajustar el ángulo del servomotor, con el objetivo de evitar el obstáculo y seguir el camino más libre.

-Detección de Obstáculos Cercanos: Si el sensor frontal (S0) detecta una distancia menor a 5 cm, el motor se detendrá durante un segundo y luego retrocederá para retomar la ruta adecuada.

-Conteo de Vueltas: Se implementó un conteo para monitorizar las señales de ajuste del servomotor. Cada vez que un sensor envía una señal para cambiar el ángulo del servomotor, se cuenta. Cuando un sensor envía esta señal 4 veces, se considera que el robot ha dado una vuelta completa. Esto permite al robot detenerse en el punto deseado del recorrido.

No obstante, se identificaron algunas fallas en esta lógica, lo que llevó a la implementación de una cámara para la detección de obstáculos basados en colores. Se realizaron ajustes en la lógica del sistema para mejorar la precisión y la eficacia en la navegación.

**Programación**
Comenzamos definiendo los objetivos de funcionamiento del robot y enfocándonos en aprender sobre programación para iniciar el proyecto. El proceso de programación se desarrolló en varias etapas:

-Introducción con RoboBloq: Inicialmente, utilizamos RoboBloq, un sistema de programación basado en bloques, para familiarizarnos con las lógicas básicas. Realizamos tareas simples como hacer que el robot avanzara y retrocediera, y posteriormente añadimos complejidad con movimientos en ángulos, giros, paradas y avances.

-Avance con miniBloq: Posteriormente, empleamos miniBloq, un lenguaje de bloques más avanzado, que nos permitió mejorar la programación de sensores, servomotores y motores. Comenzamos con ejercicios sencillos y, progresivamente, aumentamos la dificultad para adaptar el robot a tareas más complejas.

-Desarrollo con Arduino: A continuación, trabajamos con Arduino, integrando códigos simples y luego combinándolos para desarrollar funciones más complejas. Utilizamos librerías y recursos en línea para superar desafíos y optimizar la programación.

-Implementación con Raspberry Pi 3: Debido a las limitaciones de Arduino, decidimos incorporar una Raspberry Pi 3 y utilizar Python para la programación. Aunque el proceso fue desafiante, logramos desarrollar varias lógicas, empezando con códigos básicos y luego combinándolos para crear una programación más avanzada y funcional.

![Subiendo IMG_20240817_210501436_HDR_AE.jpg...]()
![Subiendo 20240905_105054.jpg...]()
