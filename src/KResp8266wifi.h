#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
ESP8266WiFiMulti WiFiMulti;
String getData;

void setWifi(char* set_SSID, char* set_PASS) {
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println("Menghubungkan ke WiFi");
  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf(".", t);
    Serial.flush();
    delay(1000);
  }
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(set_SSID, set_PASS);
}

void httpGet(String URL_GET) {
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    http.begin(URL_GET);
    int httpCode = http.GET();
    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        getData = http.getString();
      }
    } else {
      Serial.printf("Gagal, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }
}