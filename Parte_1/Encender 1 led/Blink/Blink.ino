/*  ----------------------------------------------------------------
    Encendiendo y apagando 1 LED
-------------------------------------------------------------------- */
  
void setup()                         // Parte que se realiza solo al inicio
{
  pinMode( 13 , OUTPUT) ;             // Inicializamos el pin 13 como salida
}

void loop()                           // Parte que se repite continuamente
{   
          digitalWrite( 13 , HIGH) ;   // Da voltaje en el pin 13
          delay (1000) ;              // Espera 1 segundo
          
          digitalWrite( 13 , LOW);     // Quita voltaje en el pin 13
          delay (3000) ;              // Espera 3 segundos

}

