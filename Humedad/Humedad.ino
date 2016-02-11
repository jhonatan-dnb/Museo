#define pin A5
float adc;
float voltaje;
float Porcentaje; 
float rel = 10.00;
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  adc = analogRead(pin);
  voltaje = (adc * 10 / 1023);
  Porcentaje = (100) - (voltaje * rel);
  Serial.print("Porcentaje Humedad: ");
  Serial.println(Porcentaje);
  delay(5000);
}
