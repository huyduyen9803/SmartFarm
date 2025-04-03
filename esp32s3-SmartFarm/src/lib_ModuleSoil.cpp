#include "ModuleSoil_lib.h"
//khởi tạo các chân 
void ModuleSoil_Init(void){
    pinMode(ModuleSoil_ANALOG_PIN,INPUT);
    pinMode(PUMP_RELAY_PIN,OUTPUT);
    digitalWrite(PUMP_RELAY_PIN,LOW);
}
//đọc độ ẩm đất
float ModuleSoil_readRaw(void){
    int rawValue = analogRead(ModuleSoil_ANALOG_PIN);
    float moisture = (4095 - rawValue) * 100.0 / 4095.0;
    return moisture;
}
//hàm hiển thị và xử lý
void ModuleSoil_Display(float moisture){
    //neu do am nho hon 30 thi bat máy bơm
    if(moisture<30){
        digitalWrite(PUMP_RELAY_PIN,HIGH);
        Serial.println("Pump on: Watering ...");
    }
    else{
        
        if(moisture<=45){
            Serial.println("Soil moisture is sufficient. Turning off the pump!");
        }
        else{
            digitalWrite(PUMP_RELAY_PIN,LOW);
        }
    }
}