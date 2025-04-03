#ifndef DHT22_LIB_H
#define DHT22_LIB_H
#include<Arduino.h>
#include<DHT.h>
#define DHT_PIN 2
#define DHT_TYPE DHT22
void DHT22_Init(void);
float DHT22_ReadTemperature(void);
float DHT22_ReadHumidity(void);
void DHT22_Display(void);
#endif