#ifndef BLYNK_LIB_H
#define BLYNK_LIB_H
#include<Arduino.h>
#include<WiFi.h>
#define BLYNK_TEMPLATE_ID "TMPL60DjY5paL"
#define BLYNK_TEMPLATE_NAME "SmartFarm"
#define BLYNK_AUTH_TOKEN "g9LNnwujapzGlCu1mRmPpazeLg0ib55D"
#define NO_GLOBAL_BLYNK
#include<BlynkSimpleEsp32.h>
#define WIFI_SSID "REDMI K80"
#define WIFI_PASS "huydeptrai96"

extern BlynkWifi Blynk;
extern bool relayState;
extern bool manualMode;
void Blynk_Init(void);
void Blynk_Display(void);
#endif