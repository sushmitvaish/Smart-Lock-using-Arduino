#include <ESP8266WiFi.h>

const char *ssid =  "BcQn-dmFuc2hhMTA";     // replace with your wifi ssid and wpa2 key
const char *pass =  "qwertyuiop";

WiFiClient client;
 
void setup() 
{
       Serial.begin(9600);
       delay(10);
               
       Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
}
 
void loop() 
{      
  
}
