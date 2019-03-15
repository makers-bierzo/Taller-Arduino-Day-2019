# Avancemos un poquito
En esta parte vamos a ver algunas opciones un poco más avanzadas de Arduino.
Comenzaremos hablando de la conversión del mundo analógico al digital. Para ello vamos a modificar el circuito anterior del 
relé introducciendo una fotoresistencia que será la que controlará cuando se dispara el relé.
El montaje lo podeís ver en las imagenes que están en la carpeta "montajes".

Conceptos a tener en cuenta: 
-Divisor de tensión 
-Entradas analógicas
-Resistencias pull down y pull up (aunque no seán necesarios para este ejemplo)
-PWM

Ahora vamos a avanzar un poco más y conocer una herramienta que nos facilita mucho la vida: las librerías.
Para ello vamos a utilizar un sensor de temperatura y humedad, el dht11.
El circuito nos va a mostrar a través del monitor serial los valores de Humedad, Temperatura y sensación de calor.
Para ello, como antes, el montaje lo podeís ver en las imagenes de la carpeta "montajes".

Conceptos a tener en cuenta:
-Libreria
-Monitor serial
