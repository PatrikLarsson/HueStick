#ifndef RGBLed_h
#define RGBLed_h

#include "Arduino.h"

class RGBLed
{
    public:
        RGBLed();
        void setRGB(byte red, byte green, byte blue);
        void setHSL(double h, double s, double l);
};

#endif