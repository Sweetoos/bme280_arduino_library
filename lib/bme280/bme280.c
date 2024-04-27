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
    uint8_t temperature_1 = context->read_byte(BME280_I2C_ADDRESS);

    return temperature_1;
    // atm let the function return address
}
uint8_t bme280_read_id()
{
    return context->read_byte(BME280_ID_REGISTER);
}
