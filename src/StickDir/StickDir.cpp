#include "Arduino.h"
#include "StickDir.h"

// Arduino pin numbers
const int _SW_pin = 2; // digital pin connected to switch output
const int _X_pin = 0; // analog pin connected to X output
const int _Y_pin = 1; // analog pin connected to Y output

// Due to squarish layout of joystick, corner distances will be
// and the longest distance we get is beyond 700, but since the
//vertial and horizontal extremes max out at around 500, we set that as the upper limit.
const int _maxDistance = 500; 

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
    int actualX = analogRead(_X_pin) - oX;
    return actualX;
}

// Returns the Y position, in relation to the origin.
int StickDir::getY()
{
    int actualY = analogRead(_Y_pin) - oY;
    return actualY;
}

// Returns the state of the switch (0 for off and 1 for on)
int StickDir::getSwitchState()
{
    return digitalRead(_SW_pin);
}

// Gets the distance from the center (origin), as a ratio between 0 and 1.
double StickDir::getDistance()
{
    double x = abs(
        this->getX()
    );
    double y = abs(
        this->getY()
    );
    int hyp = round(sqrt(sq(x) + sq(y)));

    // We need to convert this to a decimal between 0 and 1. We also apply
    // a jitter of 20 to avoid minor movements near the center.
    return this->convertToRatio(min(hyp, _maxDistance), 500, 10);
}

// Gets the angle of the stick, as a ration between 0 and 1.
double StickDir::getAngle()
{
    int x = this->getX();
    int y = this->getY();
    double radians = atan2(x, y);
    
    // Now we have a value between -π and π, which we convert to a decimal between 0 and 1.
    double degreeVal = ((radians / PI) + 1) / 2;
    return degreeVal;
}

double StickDir::convertToRatio(double val, int maxVal, int jitter)
{
    // Convenience function to turn an incoming value to a value between 0 and 1, with a possible jitter.
    // val: The value to convert
    // maxVal: The maximum value we can receive
    // jitter: A tolerance (from 0) which will simply return 0 if not exceeded

    maxVal = maxVal - jitter;
    double actualVal = max(val - jitter, 0);

    return actualVal / maxVal;
}