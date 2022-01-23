#include "DisplayService.h"

DisplayService::DisplayService()
{
    if (!display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("Display ERROR");
        return;
    }
    delay(250);

    ClearScreen();
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->display();
}

void DisplayService::ClearScreen() {
     display->clearDisplay();
}

void DisplayService::SplashScreen() {
    ClearScreen();
    
    display->clearDisplay();
    display->setCursor(67,0);
    display->println('Hello World');
}