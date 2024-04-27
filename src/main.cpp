#include <Arduino.h>
#include <Wire.h>
#include <bme280.h>


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
