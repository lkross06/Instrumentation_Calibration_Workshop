#include <Arduino.h>
#include "ADS8688.h"
#include <SPI.h>

//SPI pins
#define MISO 35
#define SCLK 48
#define MOSI 34

//ADC (ADS8688) settings
#define ADS8688_CS 36
#define VREF 4.1
#define RANGE 0x05

//LED indicator pin (see below)
#define LED 38

//SPI bus connecting between ESP32 and ADC
SPIClass spi(FSPI);   //The ESP32 has multiple SPI buses. FSPI sets this to the SPI3 bus

//ADS8688 interface
ADS8688 pressureADC;

void setup() {

}

void loop() {

}