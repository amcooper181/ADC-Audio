#include <Arduino.h>
#include <Wire.h>


class PCM1862 {
public:
    PCM1862(uint8_t i2cAddress);
    void verifyConnection();
    void readRegister(uint8_t registerAddress);
    void writeRegister(uint8_t registerAddress, uint8_t value);
private:
    uint8_t _i2cAddress;
    void _selectRegister(uint8_t registerAddress);
};