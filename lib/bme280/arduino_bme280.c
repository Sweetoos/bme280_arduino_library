#include "arduino_bme280.h"
#include "bme280_registers.h"
#include <Wire.h>

void arduino_i2c_init()
{
    Wire.begin();
}

uint8_t arduino_i2c_read_byte(const uint8_t address)
{
    uint8_t byte = 0;

    Wire.beginTransmission(BME280_ADDRESS);
    Wire.write(address);
    Wire.endTransmission();
    Wire.requestFrom(BME280_ADDRESS, 1);
    Wire.readBytes(&byte, 1);

    return byte;
}