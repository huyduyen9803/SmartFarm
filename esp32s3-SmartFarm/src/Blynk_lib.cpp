#include "Blynk_lib.h"
#include "DHT22_lib.h"
#include "BH1750_lib.h"
#include "ModuleSoil_lib.h"
WiFiClient wifiClient;
BlynkEsp32Client blynkTransport(wifiClient);
BlynkWifi Blynk(blynkTransport);
bool relayState;
bool manualMode = false;
void Blynk_Init(void){
    WiFi.begin(WIFI_SSID,WIFI_PASS);
    int attempt = 0;
   while (WiFi.status() != WL_CONNECTED && attempt < 20) { // Giới hạn số lần thử
        delay(500);
        Serial.print(".");
        attempt++;
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi Connected!");
        Blynk.config(BLYNK_AUTH_TOKEN); 
        Blynk.connect();
    } 
    else {
        Serial.println("\nKhông thể kết nối WiFi!");
    }
}

void Blynk_Display(void){
    Blynk.run();
    float temp = DHT22_ReadTemperature();
    float humid = DHT22_ReadHumidity();
    float lux = BH1750_ReadLux();
    float moisture = ModuleSoil_readRaw();
    Blynk.virtualWrite(V0, temp);
    Blynk.virtualWrite(V1, humid);
    Blynk.virtualWrite(V2, lux);
    Blynk.virtualWrite(V3, moisture);
}
