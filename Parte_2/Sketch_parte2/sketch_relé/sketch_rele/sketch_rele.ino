
void setup() {

//Habilitamos el puerto serie para ver la variación de valores
Serial.begin(9600);

//Preparamos la entrada 1 para que funcione como salida
pinMode(1,OUTPUT);
}

void loop() { 

int valor=analogRead(A1); //leemos los valores de la fotoresistencia
Serial.println(valor);  //sacamos por monitor serial los valores

//Creamos una estructura condicional para que accione el rele en funcion del valor de la fotoresistencia
if (valor>700){
digitalWrite(1,HIGH);
} else {
digitalWrite(1,LOW);
}

delay(500);  //esperamos un poco antes de la siguiente lectura

}
