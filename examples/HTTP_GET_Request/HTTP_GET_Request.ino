#include<KResp8266wifi.h>
char* ssid = "xxx";
char* pass = "xxx";

void setup() {
  Serial.begin(9600);
  setWifi(ssid, pass);
}

void loop() {
  httpGet("http://test.kelasrobot.com/");
  Serial.println(getData);
  delay(10000);
}
