#ifndef StickDir_h
#define StickDir_h

#include "Arduino.h"

class StickDir
{
    public:
        StickDir();
        void setup();
        int getX();
        int getY();
        int getSwitchState();
        double getDistance();
        double getAngle();
    private:
        double convertToRatio(double val, int maxVal, int jitter);
};

#endif