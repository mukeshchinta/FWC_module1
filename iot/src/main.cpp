//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "Realme 9 Pro" // Add your network credentials
#define STAPSK  "phoenix@13"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;


void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//
int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
int p,q,r;
void setup(){
  OTAsetup();
pinMode(18, OUTPUT); 
pinMode(19, OUTPUT); 
pinMode(20, OUTPUT); 
pinMode(2, INPUT);
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(5, INPUT);
pinMode(6, INPUT);
pinMode(7, INPUT);
pinMode(8, INPUT);
pinMode(9, INPUT);

  //-------------------//
  // Custom setup code //
  //-------------------//
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
a = digitalRead(2);
b = digitalRead(3);
c = digitalRead(4);
d = digitalRead(5);
e = digitalRead(6);
f = digitalRead(7);
g = digitalRead(8);
h = digitalRead(9);
p = (a&&e||!a&&!e)&&(b&&f||!b&&!f)&&(c&&g||!c&&!g)&&(d&&h||!d&&!h);
q = (d&&!h)||((c&&!g)&&(d&&h||!d&&!h))||((b&&!f)&&(c&&g||!c&&!g)&&(d&&h||!d&&!h))||((a&&!e)&&(c&&g||!c&&!g)&&(d&&h||!d&&!h)&&(b&&f||!b&&!f));
r = (!d&&h)||((!c&&g)&&(d&&h||!d&&!h))||((!b&&f)&&(c&&g||!c&&!g)&&(d&&h||!d&&!h))||((!a&&e)&&(c&&g||!c&&!g)&&(d&&h||!d&&!h)&&(b&&f||!b&&!f));
if(p){
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}
else if(q){
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
}
else if(r){
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
}
