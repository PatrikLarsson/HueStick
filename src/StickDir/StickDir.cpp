#include "Arduino.h"
#include "StickDir.h"

// Arduino pin numbers
const int _SW_pin = 2; // digital pin connected to switch output
const int _X_pin = 0; // analog pin connected to X output
const int _Y_pin = 1; // analog pin connected to Y output

// Keep track of origin coordinates.
int oX;
int oY;

StickDir::StickDir()
{
}

void StickDir::setup()
{
    // Set the right pinMode and state of the switch.
    pinMode(_SW_pin, INPUT);
    digitalWrite(_SW_pin, HIGH);
    oX = analogRead(_X_pin);
    oY = analogRead(_Y_pin);
}

// Returns the X position, in relation to the origin.
int StickDir::getX()
{
    return analogRead(_X_pin - oX);
}

// Returns the Y position, in relation to the origin.
int StickDir::getY()
{
    return analogRead(_Y_pin - oY);
}

// Returns the state of the switch (0 for off and 1 for on).
int StickDir::getSwitchState()
{
    return digitalRead(_SW_pin);
}