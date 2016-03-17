#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(9600);
dht.begin();
}
void loop() {  
  float h = dht.readHumidity();// Lee la humedad
  float t= dht.readTemperature();//Lee la temperatura

  Serial.print("Humedad Relativa: ");                 
  Serial.print(h);//Escribe la humedad
  Serial.println(" %");                     
             
  Serial.print("Temperatura: ");                  
  Serial.print(t);//Escribe la temperatura
  Serial.println(" C'");                   
                             
   delay (3000);
}
