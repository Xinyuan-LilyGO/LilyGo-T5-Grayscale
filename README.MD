<h1 align = "center">🌟LilyGo T5 Grayscale🌟</h1>

#### **English | [中文](./docs/README_CN.MD)**


### Description
-This warehouse uses T5-V2.13 driver, 4 color grayscale e-Paper, the test program driver uses [michaelkamprath/ePaperDriverLib](https://github.com/michaelkamprath/ePaperDriverLib), if you like this, please give the author homepage a Star.

### Use Arduino IDE
1. Install the correct serial port driver [CP210X Driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)
2. Copy the files in the lib directory to `~/Arduino/libraries`, and for windows users to `Documents/Arduino/libraries`
2. Open `sketch.ino` in the `sketch` directory
3. Select `ESP32 Dev Module` on the board, change the port to the correct port, and then select upload. Please note that the board does not contain `PSRAM`, please do not enable `PSRAM` in the options

### Use PlatformIO
1. Install the correct serial port driver [CP210X Driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)
1. Open this directory directly, then change your serial port in `platformio.ini`, click compile


