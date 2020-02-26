#include "AntaresESP8266HTTP.h"
#define ACCESKEY "cefa561d45e57960:9592b545c1097231"
#define WIFISSID "salma"
#define PASSWORD "joinothernetwork"

String projectName = "moisture";
String deviceName = "moisturesensor";

Antares antares (ACCESKEY);

int WET= 16; // Wet Indicator at Digital pin D0
int DRY= 2;  // Dry Indicator at Digital pin D4
int sense_Pin = 0; // sensor input at Analog pin A0

int value = 0;
void setup() {
   Serial.begin(9600);
   pinMode(WET, OUTPUT);
   pinMode(DRY, OUTPUT);
   delay(2000);
   antares.setDebug(true);
   antares.wifiConnection(WIFISSID,PASSWORD);
}
void loop() {
int temp = random(25,30);
  int hum = random(75,90);

  antares.add("wet", WET);
  antares.add("dry", DRY);

  antares.send(moisture, moisturesensor);
   Serial.print("MOISTURE LEVEL : ");
   value= analogRead(sense_Pin);
   value= value/10;
   Serial.println(value);

        if(value<50)
        {
            digitalWrite(WET, HIGH);
        }
       else
       {
           digitalWrite(DRY,HIGH);
       }

       delay(1000);

       digitalWrite(WET,LOW);

       digitalWrite(DRY, LOW);
      
}
