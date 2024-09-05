![20240905_105054](https://github.com/user-attachments/assets/b28c8818-1957-4613-b204-41e9ee13ed35)![IMG_20240817_210501436_HDR_AE](https://github.com/user-attachments/assets/cffe2ac8-6e65-4508-b61e-24e2332bcafa)# WRO-2024-LORO-SALVAJE-
Toda la información del equipo "Loro Salvaje" en la WRO 2024
Breve resumen:

La Olimpiada Mundial de Robots celebrada en Salta brinda la oportunidad de aplicar nuestros consejos teóricos en la práctica. Nos registros con la expectativa de enriquecer nuestro sentido, ya que el evento cuenta con varios equipos de la provincia.

Reunimos nuestro equipo según lo existente las reglas, compuesto por tres estudiantes y un maestro supervisor. Trabajos diligentes desde junio, con el objetivo de cumplir con nuestro plan y estar en óptimas condiciones para la competencia.

Comenzamos fabricando el chasis utilizando materiales de nuestra institución, como lugares de metal y plástico, ajustando para acumlir con los requisitos de peso y alta sugeridos por los organizadores de la competencia. Luego comenzos a construir la pieza mecánica, diseño, ajustando e instalando el motor para movimiento autónomo y el servo para dirección.

Para la programación, utilización inicial un Arduino NANO con miniBloq (diagramas de bloques). A medida que avanzaba el proyecto, nos dimos cuenta de que este sistema era limitado debido a sus lugares de conexión insuficientes para nuestros objetivos de autonomía y dirección. Decidimos reemplazarlo con un Arduino UNO, que también resultó limitado, lo que nos llevó a usar un Raspberry Pi 3 con Python. Esta configuración nos permitió participar en la competencia y se sigue mejorando hasta el día de hoy.

Este repositorio contiene todos los datos e información sobre nuestro vehículo autónomo del equipo “Loros Salvajes” (llamado así por la mascota de nuestra institución).

Utilizamos varios materiales, entre ellos:
- 3 sensores ultrasónicos
- Motor CC
- servo
- Escudo de motor L298N
- Frambuesa Pi 3
- Bateria PCBOX 20000mAh
- Sombrero sensorial (giroscopio)
- Cables de un solo núcleo
- Inglés
- Placas de metal y plástico
- Regulador LM2596

  **Construcción y Movilidad**

Al diseñar el chasis del robot, utilizamos un kit de robótica proporcionado por RobotGroup, que tenía nuestra institución. Este kit continúa varios componentes que pudimos utilizar, incluidas las placas de plástico y metal. Montamos estas lugares mediante tornillos también suministrados por la institución.
El chasis tiene unas dimensiones totales de 25x18,5 cm y una altura de 17,5 cm. La elección de estos componentes para el chasis tuvo como objetivo reducir costos y utilizar equipos poco utilizados, ya que nuestra institución tiene un enfoque "electromecánico". Como resultado, toda la programación aprendida durante el proceso fue autodidacta.

El coche cuenta con dos motores que proporcionan potencia. El primero es el motor de tracción, para el que utiliza ONU "Motor DC". A viajes de un sentido sistema de engranajes, este motor transmite potencia al eje de la rueda trasera; se fija al chasis con tornillos y el je del motor, fijado al engranaje impulsor, tambien se fija con tornillos.s.

El segundo motor es el motor de dirección, donde empleamos un servomotor "Futaba S3003", ubicado en el semidelantero del automóvil. Este servomotor está asegurado al chasis y al je de la rueda delantera con tornillos y está colocado en el medio del je para proporcionar un movimiento equilibrado en ambos lados.

Los sensores ultrasónicos están distribuidos por todo el chasis. Utilizamos tres sensores "HC-SR04": dos cada lado y un sensor adicional en la parte delantera. También incluye un controlador "L298N", ubicado en la parte superior trasera del chasis, junto a un regulador de voltaje "LM2596" conectado a una batería PCBOX.

El Raspberry Pi 3 está montado encima del servomotor, asegurado con tornillos. La "Raspberry Pi Camera Rev. 1.3" está situada en la parte delantera superior del chasis a una altura que permite la detección de obstáculos.
Para las ruedas utilizamos ruedas Robobloq. En el primer modelo utilizamos ruedas de un coche de juego, pero decidimos cambiarlas porque eran demasiado blandas, lo que provocaba inestabilidad en el robot y un movimiento direccional limitado. Las ruedas Robobloq son más firmas y aportan mayor estabilidad. Vale la pena señoralar que las ruedas están aseguradas con tornillos para evitar cualquier juego y garantizar que no se desesperdan del robot.
En el centro de las ruedas traseras conexiones un eje metálico ensamblado a un engranaje motriz. Este eje proviene de un coche de juguete y, gracias al sistema de engranajes, hace girar las ruedas cuando el motor gira.
Para las ruedas delanteras utilizamos un tipo de equipo que construyen un parter de piezas de plástico recicladas de carreras de netbook. Este eje consta de tres placas: una fijada al servomotor y dos placas de soporte paralelas para el eje vertical de la rueda. La placa conectada al servomotor transmiteeea la potencia del servomotor a las ruedas, mientras que las otras dos proporcionan estabilidad.
En la construcción también utilizamos muchos "espaciadores de caucho" para separar y estabilizar las piezas.

**Manejo de obstáculos**

Inicialmente, queríamos utilizar sensores ultrasónicos para permanecer centros en la pista y, al detectar un obstáculo, determinar en cuanto dirigir girar en función de dejar sensor detectar más espacio.
Básicamente, el sistema funciona de la segunda melena: las medidas el sensor frontal (S0) detecta una distancia superior a 20 cm, el servo permanece en 90° y el motor continúa avanzando. Si hay una desviación hace un lado, cada sensor lateral debe detectar una diferencia de distancia con respuesta a la lectura inicial. Dependencia de que sensor detecta esta diferencia, el servo se ajusta a un ángulo específico para volar a centrar el robot.

Cuando S0 detecta una distancia inferior a 20 cm, los sensores laterales (S1 y S2) miden la distancia y envian una señor para ajustar el servo a un ángulo que evita el obstáculo y siga el camino más claro. Además, si el sensor S0 detecta una distancia inferior a 5 cm, el motor debe detener durante un segundo y luego retroceder para retomar el camino correcto.

También se implementó un contador: cada vez que un sensor entorno una señal para ajustar el dentrogulo del servo, esta señal se cuenta. Cuando un sensor entorno la señor cuatro veces, se considera una vuelta. De esta forma podremos contar las vueltas para detener al robot en el punto deseado del recuerdo.

Sin embargo, entró algunos problemas con esta larga y fue necesario implementar una cámara para detectar obstáculos de colores, lo que llegó a algunos ajustes en la luz del sistema.

**Programación**

Comenzamos definidos los objetivos operativos del robot y nos centros en una programación para iniciar el proyecto. Comenzamos con RoboBloq, un sistema basado en bloques, para comprender la luz básica. Realizamos tareas sencillas, como hacer que el coche se moviera hacia adelante y hacia atrás, y luego añadimos complejidad con movimientos en ángulos, giros, paradas y avances.

Una continuación, usos miniBloq, un lenguaje basado en bloques más avanzado, que nos permitió mejorar la programación de sensores, servos y motores. Empezamos con ejercicios sencillos y poco a poco aumentamos la dificultad.

Despuestos de eso, trabajos con Arduino, integrando códigos simples y luego combinados para crear funciones más completas. Utilizamos bibliotecas y recursos en línea para superar los deseos.

Debido a las limitaciones de Arduino, decidimos implementar una Raspberry Pi 3 con Python. Aunque fue un desafío, desarrollamos con éxito diversas lógicas, comenzando siempre con códigos básicos y combinados progresivamente.
![Subiendo IMG_20240817_210501436_HDR_AE.jpg...]()
![Subiendo 20240905_105054.jpg...]()
