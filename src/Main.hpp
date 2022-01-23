#pragma once

#include <Arduino.h>
#include "Services/Display/DisplayService.hpp"
#include "Services/LoRa/LoRaService.hpp"


DisplayService *_displayService;
LoRaService *_loRaService;

void setup();
void loop();
