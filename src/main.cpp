#include <pcm1862.h>
#include <Arduino.h>
#include <ESP_I2S.h>

// Define the I2C address of the PCM1862
#define PCM1862_I2C_ADDRESS 0x4A

void i2cInitialize();

PCM1862 pcm(PCM1862_I2C_ADDRESS);
I2SClass I2S;


void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  Serial.println("Starting I2C communication...");
  i2cInitialize();
  pcm.verifyConnection();

  I2S.setPins(14, 25, 26);
  int start = I2S.begin(I2S_MODE_STD, 96000, I2S_DATA_BIT_WIDTH_32BIT, I2S_SLOT_MODE_STEREO);
}

void loop() {

}

/// @brief Initialize i2c communication on the ESP32
void i2cInitialize() {
    // Initialize I2C communication
    Wire.begin();
    Wire.setClock(400000); // Set I2C frequency to 400kHz (fast mode)

    // Delay to allow the system to stabilize
    delay(1000);
}