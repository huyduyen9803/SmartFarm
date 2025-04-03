#include "DHT22_lib.h"
//khởi tạo dht chân và dạng của nó, ở đây là chân 2, và dht22
DHT dht(DHT_PIN,DHT_TYPE);
//hàm khởi tạo
void DHT22_Init(void){
    dht.begin();
}
//đọc nhiệt độ
float DHT22_ReadTemperature(void){
    float temp = dht.readTemperature();
    if(isnan(temp)){
        Serial.println("DHT22: Error reading temperature!");
        return -999.0;
    }
    return temp;
}
//đọc độ ẩm
float DHT22_ReadHumidity(void){
    float humi = dht.readHumidity();
    if(isnan(humi)){
        Serial.println("DHT22: Error reading humidity!");
        return -99.0;
    }
    return humi;
}
//hiển thị ra
void DHT22_Display(void){
    Serial.println("Temperature: ");
    Serial.print(DHT22_ReadTemperature());
    Serial.println("*C");
    Serial.println("Humidity: ");
    Serial.print(DHT22_ReadHumidity());
    Serial.println("%");
    delay(2000);
}