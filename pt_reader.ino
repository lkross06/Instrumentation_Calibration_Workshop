#include <Arduino.h>
#include <ADS8688.h>

//SPI pins
#define MISO 37
#define SCLK 36
#define MOSI 35
#define CS1 38
#define CS2 39

//other ADC settings
#define VREF 4.1
#define RANGE 0x05

ADS8688 adc; //create ADC instance

void setup() {
    Serial.begin(115200);
    delay(1000);

    //initialize ADC
    adc.begin(MISO, SCLK, MOSI, CS1, CS2, VREF, RANGE);
    adc.setInputRange(CS1, RANGE);
    adc.setInputRange(CS2, RANGE);
}

void loop() {
    
}