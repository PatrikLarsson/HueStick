#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include <LiquidCrystal.h>

class Display
{
    public:
        Display();
        void write(int colNo, int lineNo, String line);
};

#endif