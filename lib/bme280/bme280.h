#ifndef BME280_H
#define BME280_H


#include <Wire.h>
#include <stdint.h>

typedef struct
{
    void (*init)();
    uint8_t (*read_byte)(const uint8_t address);
}impl;

impl *context;

void init_library(impl *const impl);
float readTemperature();
void init_i2c();
uint8_t read_i2c_byte(const uint8_t address);

#endif