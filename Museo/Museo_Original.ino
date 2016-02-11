#include <SPI.h>                                 
#include <SD.h>                                 
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS_1 2
#define ONE_WIRE_BUS_2 3
#define ONE_WIRE_BUS_3 5
#define ONE_WIRE_BUS_4 6

OneWire oneWire_0(ONE_WIRE_BUS_1);
OneWire oneWire_1(ONE_WIRE_BUS_2);
OneWire oneWire_2(ONE_WIRE_BUS_3);
OneWire oneWire_3(ONE_WIRE_BUS_4);

DallasTemperature sensor_0(&oneWire_0);
DallasTemperature sensor_1(&oneWire_1);
DallasTemperature sensor_2(&oneWire_2);
DallasTemperature sensor_3(&oneWire_3);

#define pin A0
float adc0;
float voltaje0;
float Porcentaje0; 
float rel_voltaje_variable = 10.00;

#define pin A1
float adc1;
float voltaje1;
float Porcentaje1;

#define pin A2
float adc2;
float voltaje2;
float Porcentaje2;

#define pin A3
float adc3;
float voltaje3;
float Porcentaje3;

const int chipSelect = 4;                        

void setup()
   {  Serial.begin(9600);
      while (!Serial)  ;                         
      Serial.print("Probando SD card...");      
      pinMode(4, OUTPUT);                      
      if (!SD.begin(chipSelect))                 
           {  
            Serial.println("No hay tarjeta");    
              return;         
           }                               
      Serial.println("Sd encontrada.");        
File dataFile = SD.open("data.txt", FILE_WRITE); 
if (dataFile)  
   {
        Serial.println("....................................");
        dataFile.println("....................................");    
        dataFile.println("Capturando Datos");    
        Serial.println("Capturando Datos");     
        for (int j=0 ; j <9999999999 ; j++)             
      {
        
  Serial.println("....................................");
  dataFile.println("....................................");
        
  adc0 = analogRead(A0);
  voltaje0 = (adc0 * 10 / 1023);
  Porcentaje0 = (100) - (voltaje0 * rel_voltaje_variable);
  Serial.print("Porcentaje Humedad0: ");
  Serial.println(Porcentaje0);
  dataFile.println("Porcentaje Humedad0: " + String(Porcentaje0));
  dataFile.flush();

  adc1 = analogRead(A1);
  voltaje1 = (adc1 * 10 / 1023);
  Porcentaje1 = (100) - (voltaje1 * rel_voltaje_variable);
  Serial.print("Porcentaje Humedad1: ");
  Serial.println(Porcentaje1);
  dataFile.println("Porcentaje Humedad1: " + String(Porcentaje1));
  dataFile.flush();

  adc2 = analogRead(A2);
  voltaje2 = (adc2 * 10 / 1023);
  Porcentaje2 = (100) - (voltaje2 * rel_voltaje_variable);
  Serial.print("Porcentaje Humedad2: ");
  Serial.println(Porcentaje2);
  dataFile.println("Porcentaje Humedad2: " + String(Porcentaje2));
  dataFile.flush();

  adc3 = analogRead(A3);
  voltaje3 = (adc3 * 10 / 1023);
  Porcentaje3 = (100) - (voltaje3 * rel_voltaje_variable);
  Serial.print("Porcentaje Humedad3: ");
  Serial.println(Porcentaje3);
  dataFile.println("Porcentaje Humedad3: " + String(Porcentaje3));
  dataFile.flush();
  Serial.println("....................................");
  dataFile.println("....................................");

  Serial.println("Dallas Temperature Control");

  sensor_0.begin();
  sensor_1.begin();
  sensor_2.begin();
  sensor_3.begin();

  Serial.print("Requesting temperatures...");
  sensor_0.requestTemperatures();
  sensor_1.requestTemperatures();
  sensor_2.requestTemperatures();
  sensor_3.requestTemperatures();
  Serial.println(" done");

  Serial.print("Temperatura 0: ");
  Serial.println(sensor_0.getTempCByIndex(0));
  dataFile.println("Temperatura 0: " + String(sensor_0.getTempCByIndex(0)));
  dataFile.flush();
  
  Serial.print("Temperatura 1: ");
  Serial.println(sensor_1.getTempCByIndex(1));
  dataFile.println("Temperatura 1: " + String(sensor_0.getTempCByIndex(1)));
  dataFile.flush();
  
  Serial.print("Temperatura 2: ");
  Serial.println(sensor_2.getTempCByIndex(2));
  dataFile.println("Temperatura 2: " + String(sensor_0.getTempCByIndex(2)));
  dataFile.flush();
  
  Serial.print("Temperatura 3: ");
  Serial.println(sensor_3.getTempCByIndex(3));
  dataFile.println("Temperatura 3: " + String(sensor_0.getTempCByIndex(3)));
  dataFile.flush();
  
  Serial.println("....................................");
  dataFile.println("....................................");

          delay(3600000);
      }

        dataFile.flush();                       
        Serial.println("Listo. Terminado");     
   }}

   
   void loop ()
   {}
