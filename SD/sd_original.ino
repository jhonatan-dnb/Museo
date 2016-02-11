#include <SPI.h>                            
#include <SD.h> 
                               
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
   {    dataFile.println("Capturando Datos");   
        Serial.println("Capturando Datos");     
        for (int j=0 ; j <20 ; j++)              



   
        dataFile.close();                        
        Serial.println("Listo. Terminado");      
   }}

   
   void loop ()
   {}
