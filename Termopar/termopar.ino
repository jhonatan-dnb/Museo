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

void setup(void)
{
    Serial.begin(9600);
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

    Serial.print("Sensor 0: ");
    Serial.println(sensor_0.getTempCByIndex(0));

    Serial.print("Sensor 1: ");
    Serial.println(sensor_1.getTempCByIndex(0));
    
    Serial.print("Sensor 2: ");
    Serial.println(sensor_2.getTempCByIndex(0));

    Serial.print("Sensor 3: ");
    Serial.println(sensor_3.getTempCByIndex(0));
    
    delay (3000);
    
}

void loop(void)
{}
