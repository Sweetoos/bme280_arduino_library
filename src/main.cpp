#include <Arduino.h>
#include <Wire.h>

#define BME280_ADDRESS 0xD0

struct impl
{
  void (*init)();
  uint8_t (*read_byte)(const uint8_t address);
};

impl *context;

void init_library(impl* const impl)
{
  context = impl;
  context->init();
}

float readTemperature()
{
  uint8_t temperature_1 = context->read_byte(BME280_ADDRESS);

  return temperature_1;
  //atm let the function return address 
}

void init_i2c()
{
  Wire.begin();
}

uint8_t read_i2c_byte(const uint8_t address)
{
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  Wire.requestFrom(BME280_ADDRESS, 1);
  return Wire.available() ? Wire.read() : 0;
}
void setup() 
{
  impl lib_impl;
  lib_impl.init = init_i2c;
  lib_impl.read_byte = read_i2c_byte;
  init_library(&lib_impl);
  Serial.begin(9600);
}

void loop() 
{
  float temp = readTemperature();
  Serial.println(temp);
}
