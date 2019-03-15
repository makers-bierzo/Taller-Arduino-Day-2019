/*  ----------------------------------------------------------------
    Encendiendo y apagando 2 LEDs y un relé
-------------------------------------------------------------------- */
/* Parametros control */
#define OUPUT_PIN_LED_A 13 // LED
#define OUPUT_PIN_LED_B 12 // LED
#define OUPUT_PIN_RELE 1 // Control del relé
  
void setup()                         // Parte que se realiza solo al inicio
{
  pinMode( OUPUT_PIN_LED_A , OUTPUT) ;             // Inicializamos el pin 13 como salida
  pinMode( OUPUT_PIN_LED_B , OUTPUT) ;             // Inicializamos el pin 12 como salida
  pinMode( OUPUT_PIN_RELE , OUTPUT) ;             // Inicializamos el pin 12 como salida
}

void loop()                           // Parte que se repite continuamente
{   
          digitalWrite( OUPUT_PIN_LED_A , HIGH) ;   // Da voltaje en el pin 13
          digitalWrite( OUPUT_PIN_LED_B , HIGH) ;   // Da voltaje en el pin 12
          digitalWrite( OUPUT_PIN_RELE , HIGH) ;   // Da voltaje en el pin 1
          delay (1000) ;              // Espera 1 segundo
          
          digitalWrite( OUPUT_PIN_LED_A , LOW);     // Quita voltaje en el pin 13
          digitalWrite( OUPUT_PIN_LED_B , LOW);     // Quita voltaje en el pin 12
          digitalWrite( OUPUT_PIN_RELE , LOW);     // Quita voltaje en el pin 1
          delay (3000) ;              // Espera 3 segundos

}

