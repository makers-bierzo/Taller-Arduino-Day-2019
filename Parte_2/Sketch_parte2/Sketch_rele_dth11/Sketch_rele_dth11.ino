#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7
#define DHTTYPE DHT11
float temp = 0;
float hume = 0;
int vez = 0;
DHT dht(DHTPIN, DHTTYPE);

void setup() {

Serial.begin(9600);
dht.begin();
pinMode(1,OUTPUT);
}

void loop() {

delay(5000);
float h = dht.readHumidity();
float t = dht.readTemperature();
int valor=analogRead(A1);

if (isnan(h) || isnan(t)) {
Serial.println("Error obteniendo los datos del sensor DHT11");
return;
}

float hic = dht.computeHeatIndex(t, h, false);
vez++;
if (temp != t || hume != h) {
Serial.print("Humedad: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperatura: ");
Serial.print(t);
Serial.print(" *C \t");
Serial.print("Índice de calor: ");
Serial.print(hic);
Serial.print(" *C \t");
Serial.println(vez);
temp = t;
hume = h;
}

Serial.print("LDR: ");
Serial.println(valor);
if (valor>700) {
  digitalWrite(1,HIGH);
} else {
  digitalWrite(1,LOW);
}
}
