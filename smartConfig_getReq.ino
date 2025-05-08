
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  pinMode(2, OUTPUT);
  pinMode(27, OUTPUT);

  digitalWrite(2, LOW);
  digitalWrite(27, LOW);
  
  //Init WiFi as Station, start SmartConfig
  WiFi.mode(WIFI_AP_STA);
  WiFi.beginSmartConfig();

  //Wait for SmartConfig packet from mobile
  Serial.println("Waiting for SmartConfig.");
  while (!WiFi.smartConfigDone()) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("SmartConfig received.");

  //Wait for WiFi to connect to AP
  Serial.println("Waiting for WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected.");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
 if (WiFi.status() == WL_CONNECTED){

HTTPClient http;

http.begin("https://retoolapi.dev/XB1y0H/data");
Serial.println(".");  
int httpCode = http.GET();
Serial.println(".");   

if (httpCode > 0){
  String payload = http.getString(); 
        
  payload.replace('[', ' ');
  payload.replace(']', ' ');
  char json[500];
  payload.toCharArray(json, 500);
  StaticJsonDocument<1024> doc;
  deserializeJson(doc, json);
  String led1 = doc["rele1"];
  Serial.print("led1 :");
  Serial.println(led1);
  if(led1== "1") digitalWrite(2, HIGH);
  else digitalWrite(2, LOW);
  String led2 = doc["rele2"];
  if(led2 == "1") digitalWrite(27, HIGH);
  else digitalWrite(27, LOW);
  Serial.print("led2 :");
  Serial.println(led2);
}

http.end();  
}else{
Serial.println("Check your internet connection");
}



}
