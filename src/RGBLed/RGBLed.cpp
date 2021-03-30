#include "Arduino.h"
#include "RGBLed.h"

// Define Pins
const int _RED = 13;
const int _GREEN = 12;
const int _BLUE = 11;

RGBLed::RGBLed()
{
    pinMode(_RED, OUTPUT);
    pinMode(_GREEN, OUTPUT);
    pinMode(_BLUE, OUTPUT);
}

void RGBLed::setRGB(byte red, byte green, byte blue)
{
    analogWrite(_RED, red);
    analogWrite(_GREEN, green);
    analogWrite(_BLUE, blue);
}

void RGBLed::setHSL(double h, double s, double l) 
{

}