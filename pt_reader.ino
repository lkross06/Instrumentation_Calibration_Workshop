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
  Serial.begin(115200);   //baud rate = 115200 baud
  delay(1000);

  //This pin controls an orange LED in the middle of the DAQ. We will
  //  turn on the LED when our program starts, so we know that our
  //  code was flashed + executed successfully.
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  //Start SPI bus
  spi.begin(SCLK, MISO, MOSI, ADS8688_CS);

  //Initialize ADC
  pressureADC.begin(MISO, SCLK, MOSI, ADS8688_CS, -1, VREF, RANGE);    //this library connects to 2 ADCs, and this board has the second ADC's CS on pin 7
  pressureADC.setInputRange(ADS8688_CS, RANGE);    //don't worry about this setting too much for now

  Serial.println("Initialization complete.");
}

void loop() {
  //The PT ADC has 8 channels to read PTs from. We only have 1 PT connected rn,
  //  so we only will print one of these values (the others are floating-- nonsense noise)
  float ptVoltages[8];
  
  pressureADC.readAllChannels(ADS8688_CS, true, ptVoltages);

  /* ======================================================================================= */
  /* HERE IS WHERE YOU WOULD PUT YOUR LINEAR REGRESSION COEFFICIENTS AND CALIBRATE THE VALUE */
  /* ======================================================================================= */

  Serial.println(ptVoltages[7] / 2);    //Ryan hopefull will hook up the PT to PT0 on the DAQ...

  delay(200);   //wait 200ms before reading again
}