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
uint8_t bme280_read_id();

#endif