#ifndef ModuleSoil_LIB_H
#define ModuleSoil_LIB_H
#include<Arduino.h>
#define ModuleSoil_ANALOG_PIN 34   // Chân ADC đo độ ẩm
#define PUMP_RELAY_PIN 5   // Chân digital kiểm tra trạng thái khô/ướt
void ModuleSoil_Init(void);
float ModuleSoil_readRaw(void);
void ModuleSoil_Display(float moisture);
#endif