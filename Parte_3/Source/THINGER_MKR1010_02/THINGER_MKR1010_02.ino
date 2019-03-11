#include <WiFiNINA.h>
#include <ThingerWifi101.h>
#include "DHT.h"

#define USERNAME "**********"
#define DEVICE_ID "**********"
#define DEVICE_CREDENTIAL "**********"

#define SSID "**********"
#define SSID_PASSWORD "**********"

// ELEMENTOS DEL SENSOR DHT 
#define DHTPIN 2        // Pin Digital conectado al sensor DHT 
#define DHTTYPE DHT11   // Tipo DHT 11
// Inicializar el sensor DHT.
DHT dht(DHTPIN, DHTTYPE);
float temperatura;
float humedad;
// ELEMENTOS DEL RELE
#define RELEPIN 0        // Pin Digital conectado al RELE

// VARIABLES DE TEMPORIZACION
unsigned long currentMillis;
unsigned long previousMillis = 0;
unsigned long interval = 0; 
int Var_inter_medir;

ThingerWifi101 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);


// Función para leer los datos del sensor
void Leer_DHT11(){
  // Leer la humedad
  humedad = dht.readHumidity();
  //Leer la temperatura como Celsius (el valor predeterminado)
  temperatura = dht.readTemperature();

  // Compruebe si alguna de las lecturas ha fallado y salga antes (para intentarlo de nuevo).  
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println(F("¡Error al leer del sensor DHT!"));
    return;
  }
  // Lo visualizo por el puerto serie
  Serial.print(F("Humedad: "));
  Serial.print(humedad);
  Serial.println(" %");
  Serial.print(F("Temperatura: "));
  Serial.print(temperatura);
  Serial.println(" ºC");
}
  
void setup() {
  // Configuro la red wifi
  thing.add_wifi(SSID, SSID_PASSWORD);

  Serial.begin(9600);
  Serial.println(F("Iniciciando ...!"));
  dht.begin();
  
  // Pines comos salidas 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELEPIN, OUTPUT);
  digitalWrite(PIN_LED,LOW);

  // ----------------------------------------
  // Creamos los recursos DE ENTRADA para la API
  // ----------------------------------------
  // pin control example (i.e. turning on/off a light, a relay, etc)
  thing["Rele"] << digitalPin(RELEPIN);

  // ----------------------------------------
  // Creamos los recursos DE SALIDA para la API
  // ----------------------------------------
    thing["thp11"] >> [](pson & out) {
      out["thp11_temperatura"] = temperatura;
      out["thp11_humedad"] = humedad;
  };

  // more details at http://docs.thinger.io/arduino/
  
  Var_inter_medir = 1;  // Cada 5 segundos actualizamos el dato
}

void loop() {
  thing.handle();
  
  //Leer los datos del sensor cada Var_inter_medir segundos
  currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    interval=Var_inter_medir*1000;
    digitalWrite(PIN_LED, !digitalRead(PIN_LED));
    Leer_DHT11();
    thing.stream(thing["thp11"]);
}
}
