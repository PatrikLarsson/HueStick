#include "Arduino.h"
#include "Display.h"
#include <LiquidCrystal.h>

LiquidCrystal _lcd(3, 4, 5, 6, 7, 8);

Display::Display()
{
    _lcd.begin(16, 2);
}

// Shorthand function to output a string on the right col and row.
void Display::write(int colNo, int lineNo, String str) 
{
    _lcd.setCursor(colNo, lineNo);
    _lcd.print(str);
}