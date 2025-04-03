#ifndef BH1750_LIB_H
#define BH1750_LIB_H
#include<Arduino.h>
#include<BH1750.h>
#include<Wire.h>
#define BH1750_ADDR 0x23
#define LED_PIN 4
#define MAX_LUX 300
#define MIN_LUX 100
void BH1750_Init(void);
float BH1750_ReadLux(void);
void BH1750_Display(void);
#endif  