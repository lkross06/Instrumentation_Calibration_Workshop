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
SPIClass spi_bus(FSPI);     //The ESP32 has multiple SPI buses, and FSPI is the SPI3 bus

//ADC instance
ADS1256 adc(DRDY, RESET, SYNC, CS, VREF, &spi_bus);

void setup() {
    Serial.begin(115200);
    delay(1000);

    //configure SPI pins
    pinMode(MISO, INPUT_PULLUP);
    pinMode(SCLK, OUTPUT);
    pinMode(MOSI, OUTPUT);

    //initialize the SPI bus with custom pins
    spi_bus.begin(SCLK, MISO, MOSI, CS);

    //ADC Setup
    adc.InitializeADC();            //setup spi interface
    adc.setPGA(PGA_64);             //improve resolution for small signals by 64x
    adc.setMUX(DIFF_0_1);           //ready differentially (compare analog input 0 to analog input 1)
    adc.setDRATE(DRATE_1000SPS);    //set data rate to 1k sps

    delay(1000);
}

void loop() {
  
}