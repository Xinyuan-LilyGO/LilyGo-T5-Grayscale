#include <ePaperDriver.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
#include <SPI.h>
#include <SD.h>

ePaperDisplay *device = nullptr;

#define SPI_MOSI            (23)
#define SPI_MISO            (-1)
#define SPI_CLK             (18)

#define ELINK_SS            (5)
#define ELINK_BUSY          (4)
#define ELINK_RESET         (16)
#define ELINK_DC            (17)

#define SDCARD_SS           (13)
#define SDCARD_CLK          (14)
#define SDCARD_MOSI         (15)
#define SDCARD_MISO         (2)

#define BUTTON_PIN          (39)

SPIClass                    SDSPI(VSPI);
String                      message = "";

void setup()
{
    Serial.begin(115200);
    device = new ePaperDisplay(GDEW0213T5, ELINK_BUSY, ELINK_RESET, ELINK_DC, ELINK_SS);

    SDSPI.begin(SDCARD_CLK, SDCARD_MISO, SDCARD_MOSI, SDCARD_SS);

    if (!SD.begin(SDCARD_SS, SDSPI)) {
        Serial.println("SD Card FAIL");
        message = "SD NULL";
    } else {
        Serial.println("SD Card PASS");
        uint32_t cardSize = SD.cardSize() / (1024 * 1024);
        message = "SDCard:" + String(cardSize) + "MB";
        Serial.println(message);
    }

}

void loop()
{
    //
    // demonstrate using the Adafruit GFX primitives to draw an image
    //
    device->setFont(&FreeSans9pt7b);
    device->setTextColor(ePaper_BLACK);
    device->setRotation(0);

    const __FlashStringHelper *str = F("LilyGo");
    int16_t x1, y1;
    uint16_t w, h;

    // clean screen
    device->clearDisplay();
    device->refreshDisplay();

    //
    // demonstrate drawing to a "rotated" screen
    //
    device->setFont(&FreeSansBold18pt7b);
    device->setTextColor(ePaper_INVERSE1);
    device->setRotation(1);
    device->clearDisplay();
    device->fillTriangle(
        0, 0,
        device->width() - 1, 0,
        0, device->height() - 1,
        ePaper_GRAY2
    );
    device->fillTriangle(
        0, device->height() - 1,
        device->width() - 1, 0,
        device->width() - 1, device->height() - 1,
        ePaper_GRAY1
    );

    device->getTextBounds(str, 0, 0, &x1, &y1, &w, &h);
    device->setCursor(device->width() / 2 - w / 2, device->height() / 2 - 14 );
    device->print(str);
    device->setFont(&FreeSans9pt7b);

    device->getTextBounds(message, 0, 0, &x1, &y1, &w, &h);
    device->setCursor(device->width() / 2 - w / 2, device->height() / 2 + 5 + h );
    device->print(message);


    device->setFont(&FreeMono9pt7b);
    device->setTextColor(ePaper_INVERSE3);
    message = "GDEW0213T5";
    device->getTextBounds(message, 0, 0, &x1, &y1, &w, &h);
    device->setCursor(device->width() - w, device->height() - h );
    device->print(message);

    device->refreshDisplay();

    // goto sleep
    esp_sleep_enable_ext0_wakeup((gpio_num_t)BUTTON_PIN, LOW);

    esp_deep_sleep_start();
}
