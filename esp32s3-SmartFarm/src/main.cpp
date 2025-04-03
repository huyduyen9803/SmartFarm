#include "BH1750_lib.h"
#include "DHT22_lib.h"
#include "ModuleSoil_lib.h"
#include "Blynk_lib.h"
void setup(){
    Serial.begin(115200);
    BH1750_Init();
    DHT22_Init();
    ModuleSoil_Init();
    Blynk_Init();
}
void loop(){
    BH1750_Display();
    DHT22_Display();
    float moisture = ModuleSoil_readRaw();
    Serial.print(moisture);
    Serial.println("%");
    ModuleSoil_Display(moisture);
    Blynk_Display();
}