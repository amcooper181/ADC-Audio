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
  int8_t bck = 14;
  int8_t ws = 25;
  int8_t dout = 13;
  int8_t din = 26;
  I2S.setPins(bck, ws, dout, din);
  int start = I2S.begin(I2S_MODE_STD, 96000, I2S_DATA_BIT_WIDTH_32BIT, I2S_SLOT_MODE_STEREO);
}
const int buff_size = 4096;
char buffer[buff_size];
int available_bytes, read_bytes;


void loop() {

  I2S.read();
  available_bytes = I2S.available();

  read_bytes = I2S.readBytes(buffer, available_bytes < buff_size ? available_bytes : buff_size);

  for (int i = 0; i < read_bytes; i += sizeof(buffer)) {
    I2S.write((uint8_t *) &buffer[i], std::min(buff_size, read_bytes - i));
  }
}

/// @brief Initialize i2c communication on the ESP32
void i2cInitialize() {
    // Initialize I2C communication
    Wire.begin();
    Wire.setClock(400000); // Set I2C frequency to 400kHz (fast mode)

    // Delay to allow the system to stabilize
    delay(1000);
}