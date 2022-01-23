#pragma once

#include "stdlib.h"
#include "string"
#include <iostream>
#include <sstream>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"
#include "../../Config.h"
#include "DisplayIcons.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)

class DisplayService
{
public:
    DisplayService();
    void SplashScreen();

private:
	Adafruit_SSD1306* _display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
};

