#ifndef ARDUINO_BME280_H
#define ARDUINO_BME280_H

void arduino_i2c_init();
uint8_t arduino_i2c_read_byte(const uint8_t address);

#endif