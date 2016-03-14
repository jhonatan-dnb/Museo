#include <math.h>

int analogPin1 = 0;
double tempMin = 0.0;

float Vin = 5.0;     // [V]       Tensión alimentación del divisor
float Rfija = 1000;  // [ohm]     Resistencia fija del divisor
float R25 = 10000;    // [ohm]     Valor de NTC a 25ºC
float Beta = 3435.0; // [K]      Parámetro Beta de NTC
float T0 = 293.15;   // [K]       Temperatura de referencia en Kelvin

float Vout = 0.0;    // [V]       Variable para almacenar Vout
float Rntc = 0.0;    // [ohm]     Variable para NTC en ohmnios

float TempK = 0.0;   // [K]       Temperatura salida en Kelvin
float TempC = 0.0;   // [ºC]      Temperatura salida en Celsius

void setup() {
  Serial.begin(9600);
  pinMode(analogPin1, INPUT);
}

void loop()
{

  Vout=(Vin/1024)*(analogRead(analogPin1));       //Primero la Vout del divisor
  Rntc=(Vout*Rfija)/(Vin-Vout);                   //Ahora la resistencia de la NTC
  TempK = Beta/(log(Rntc/R25)+(Beta/T0));         //Y por último la temperatura en Kelvin
  TempC = TempK-273.15;                           //Y ahora la pasamos a celsius

  Serial.println();
  Serial.print("Temperatura:");
  Serial.print(TempC);
  Serial.println(" C");
  Serial.println();
  delay(5000);
}
