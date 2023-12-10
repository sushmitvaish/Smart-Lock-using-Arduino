#include <Firebase.h>  
#include <FirebaseArduino.h>  
#include <FirebaseCloudMessaging.h>  
#include <FirebaseError.h>  
#include <FirebaseHttpClient.h>  
#include <FirebaseObject.h>  
#include <Servo.h>

Servo servo;
  
//  
// Copyright 2015 Google Inc.  
//  
// Licensed under the Apache License, Version 2.0 (the "License");  
// you may not use this file except in compliance with the License.  
// You may obtain a copy of the License at  
//  
//     http://www.apache.org/licenses/LICENSE-2.0  
//  
// Unless required by applicable law or agreed to in writing, software  
// distributed under the License is distributed on an "AS IS" BASIS,  
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  
// See the License for the specific language governing permissions and  
// limitations under the License.  
//  
  
// FirebaseDemo_ESP8266 is a sample that demo the different functions  
// of the FirebaseArduino API.  
  
#include <ESP8266WiFi.h>  
#include <FirebaseArduino.h>  
  
// Set these to run example.  
#define FIREBASE_HOST "smart-lock-2019.firebaseio.com"
#define FIREBASE_AUTH "inoR7CsJJHcccSR2R6STKjfjyGmlYiO5DP6ovxuQ"
#define WIFI_SSID "AndroidAP"
#define WIFI_PASSWORD "12345678" 
  
void setup() {  
  Serial.begin(9600);  
  servo.attach(2); //D4
  // connect to wifi.  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  
  Serial.print("connecting");  
  while (WiFi.status() != WL_CONNECTED) {  
    Serial.print(".");  
    delay(500);  
  }  
  Serial.println();  
  Serial.print("connected: ");  
  Serial.println(WiFi.localIP());  
    
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  
  pinMode(LED_BUILTIN,OUTPUT);    
}  

void lock() {
  servo.write(100);
  delay(1000);
}
void unlock() {
  servo.write(0);
  delay(1000);
}

int n;  
  
void loop() {  
  // set value  
  n=Firebase.getInt("LOCK_STATUS");    
  if (n == 1) {  
      Serial.print("LOCKED");  
      lock();
      digitalWrite(LED_BUILTIN, LOW);  // works in reverse for some reason, low here means high
      Serial.println(Firebase.error());    
      return;  
      delay(100);  
  }  
 else if (n == 2) {  
   Serial.print("UNLOCKED");
   unlock();  
   digitalWrite(LED_BUILTIN, HIGH);  // means low
 }  
    
  delay(1000); // delay to decrease bandwith
    
}  
