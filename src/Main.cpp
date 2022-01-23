#include "Main.hpp"


void setup()
{
    Serial.begin(115200);

    _displayService = new DisplayService();
    _loRaService = new LoRaService();

    _displayService->SplashScreen();
    _loRaService->Initialize();
}

void loop()
{
    _loRaService->CheckForNewMessages();
}
