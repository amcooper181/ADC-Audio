# ESP32 Analog to Digital Streamer

## Overview

The **ESP32 Analog to Digital Streamer** is a project designed to capture analog audio signals and stream them using the ESP32 microcontroller. The PCM1862 ADC this project is based on is feature-rich, highly customizable, and offers a 100dB+ signal to noise ratio.

## Features

- **High-Quality Audio Capture:** Utilizes the PCM1862 codec for precise analog-to-digital conversion.
- **Real-Time Streaming:** Stream audio data over Wi-Fi using the ESP32's built-in capabilities.
- **High Sample Rate:** 96 kHz at 24 bits
- **Low Latency:** Optimized for low-latency streaming to ensure real-time audio processing.
- **Input Options:** This device allows for inputs via a 3.5mm TRRS connector or RCA cables
- **Input Levels:** Supports line-level inputs. The PCM1862 has a configurable, 2 level gain amplifier that can be used for phono inputs, but for the best quality a dedicated, external amplifier is recommended.

## Getting Started

### Hardware

- **Prototype Stage** The KiCad files are available for the first prototype, located in [adcesp32_kicad/](./adcesp32_kicad//)
- **Power Supply** The device requires a USB-C power supply.

### Software

- **Building the Project** All files needed to build the project in PlatformIO are included in this repo
- **Basic Functionality** As of now, the software included in this repo will allow the user to convert an analog input to digital output. An I2S amplifier can be can be connected to listen to playback.
- **Buffered Data** The data is buffered before being sent to the DOUT pin on the PCM1862. This was done to prototype data processing speed.
- **Work In Progress** The software will be updated, improved, and finalized upon finalization of the hardware. The hardware is currently on order, and 5 demo boards should arrive by 9/1/2024

### License
This project is licensed under the GPL V3 License. See the [LICENSE](./LICENSE) file for details.
