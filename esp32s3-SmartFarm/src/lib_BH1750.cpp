#include "BH1750_lib.h"
BH1750 Lightmeter;
void BH1750_Init(void){
    Wire.begin();
    Lightmeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
    pinMode(LED_PIN,OUTPUT);
    ledcSetup(0, 5000, 8);  // Tần số 5kHz, độ phân giải 8-bit
    ledcAttachPin(LED_PIN, 0); // Chọn kênh PWM 0 cho LED_PIN 
}
float BH1750_ReadLux(void){
    float lux = Lightmeter.readLightLevel();
    if(isnan(lux)){
        Serial.println("BH1750: Error reading lux!");
        return 0;
    }
    return lux;
}
void BH1750_Display(){
    int brightness;
    float lux = BH1750_ReadLux();
    Serial.print("Lux: ");
    Serial.println(lux);
    if (lux > MAX_LUX) {
        brightness = 50;
    } else if (lux < MIN_LUX) {
        brightness = 255;
    } else {
        brightness = map(lux, MIN_LUX, MAX_LUX, 255, 50);
    }

    ledcWrite(0, brightness);
}
