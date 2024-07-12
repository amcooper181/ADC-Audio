#include <pcm1862.h>

// Define the I2C address of the PCM1862
#define PCM1862_I2C_ADDRESS 0x4B

void i2cInitialize();

PCM1862 pcm(PCM1862_I2C_ADDRESS);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  Serial.println("Starting I2C communication...");
  i2cInitialize();
  pcm.verifyConnection();

}

void loop() {
  // Read the contents of PCM1862 register 0x78
  pcm.readRegister(0x78);

  // Delay before the next iteration
  delay(10);
}

/// @brief Initialize i2c communication on the ESP32
void i2cInitialize() {
    // Initialize I2C communication
    Wire.begin();
    Wire.setClock(400000); // Set I2C frequency to 400kHz (fast mode)

    // Delay to allow the system to stabilize
    delay(1000);
}