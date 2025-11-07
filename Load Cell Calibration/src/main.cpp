#include <Arduino.h>
#include <SPI.h>
#include <ADS1256.h>

//SPI pins
#define MISO 37
#define SCLK 36
#define MOSI 35
#define CS   34

//ADS1256 settings
#define VREF 2.5        //voltage reference
#define DRDY 4          //Data Ready pin --> pinged when data is received
#define RESET -1        //TODO: i don't know what these pins are
#define SYNC -1

//SPI bus
SPIClass spi(FSPI);     //The ESP32 has multiple SPI buses, and FSPI is the SPI3 bus

//ADC instance
ADS1256 adc(DRDY, RESET, SYNC, CS, VREF, &spi);

void setup() {
    
}

void loop() {
  
}