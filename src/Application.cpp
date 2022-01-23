#include "Application.h"

void setup()
{
    Serial.begin(115200);
    
    _displayService = new DisplayService();
    _displayService->SplashScreen();
}

void loop()
{
    delay(1000);
}