#include "DisplayService.h"

DisplayService::DisplayService()
{
    if (!_display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("Cannot connect to display");
        return;
    }

    delay(250);

    _display->clearDisplay();
    _display->setTextSize(1);
    _display->setTextColor(WHITE);
    _display->display();
}

void DisplayService::SplashScreen() {
    _display->clearDisplay();
    
    _display->setCursor(67,10);
    _display->println(OS_NAME);

    _display->drawBitmap(10, 10, LOGO44, 44, 44, WHITE);

    _display->setCursor(67, 20);
    _display->println(OS_VERSION);

    _display->display();
}