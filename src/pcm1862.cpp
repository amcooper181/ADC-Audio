#include <pcm1862.h>

/// @brief Main Class Initializer for the PCM1862 object.
/// @param i2c_address The i2c address of the PCM1862, in slave mode (0x4A, 0x4B) determined by pin 25 LOW or HIGH
PCM1862::PCM1862(uint8_t i2cAddress) : _i2cAddress(i2cAddress) {}

void PCM1862::verifyConnection() {
    Wire.beginTransmission(_i2cAddress);
    uint8_t error = Wire.endTransmission();
    if (!error) {
        Serial.println("PCM1862 found.");
    }
    else {
        Serial.print("Could not conect to PCM1862 due to error: ");
        Serial.println(error);
    }
}

void PCM1862::_selectRegister(uint8_t registerAddress) {

    Wire.beginTransmission(_i2cAddress);
    Wire.write(0x78);
    Wire.endTransmission(false);  // Set false to keep control of the bus, because there will always be a read/write after.
}

void PCM1862::readRegister(uint8_t registerAddress) {
    _selectRegister(registerAddress);
    Wire.requestFrom(_i2cAddress, 1);  // 1 Byte registers  
    if (Wire.available()) {  // Don't block if there isn'y aynthing to read.
        byte readByte = Wire.read();
        Serial.print("Read Byte: ");
        Serial.println(readByte, HEX);
    }
    else {
        Serial.println("Failed to read data from PCM1862");
    }
}

void PCM1862::writeRegister(uint8_t registerAddress, uint8_t value) {
    _selectRegister(registerAddress);
    Wire.beginTransmission(_i2cAddress);  // 1 Byte registers  
    Wire.write(val);
    Wire.endTransmission();
}