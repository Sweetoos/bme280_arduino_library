#include "bme280.h"
#include "bme280_registers.h"



impl* context;

void init_library(impl *const impl)
{
    context = impl;
    context->init();
}

float readTemperature()
{
    uint8_t temperature_1 = context->read_byte(BME280_ADDRESS);

    return temperature_1;
    // atm let the function return address
}

uint8_t read_i2c_byte(const uint8_t address)
{
    Wire.beginTransmission(BME280_ADDRESS);
    Wire.write(address);
    Wire.endTransmission();
    Wire.requestFrom(BME280_ADDRESS, 1);
    return Wire.available() ? Wire.read() : 0;
}
uint8_t bme280_read_id()
{
    return context->read_byte(BME280_ID_REGISTER);
}
