<h1 align = "center">🌟LilyGo T5 Grayscale🌟</h1>

#### **[English](../README.MD) | 中文**


### 描述
- 这个仓库使用T5-V2.13驱动,4灰阶电子纸,该测试程序驱动使用[michaelkamprath/ePaperDriverLib](https://github.com/michaelkamprath/ePaperDriverLib),如果你喜欢这个请给作者主页点个Star


### 使用Arduino IDE 
1. 安装正确的串口驱动程序 [CP210X Driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)
2. 将lib目录内文件拷贝到`~/Arduino/libraries`,windows 用户拷贝到 `Documents/Arduino/libraries`
2. 打开`sketch`目录下的`sketch.ino`
3. 板子选择`ESP32 Dev Module`,更改端口为正确的端口，然后选择上传,请注意该板子未包含`PSRAM`,请勿在选项中开启`PSRAM`

### 使用PlatformIO
1. 安装正确的串口驱动程序 [CP210X Driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)
1. 直接打开本目录,然后在`platformio.ini`中更改你的串口端口，点击编译即可



