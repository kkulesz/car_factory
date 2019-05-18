#ifndef _CAR_H_
#define _CAR_H_

#include "frame.h"
#include "engine.h"
#include "battery.h"

class Car{
public:
    enum Colour{RED, GREEN, BLUE, WHITE, BLACK};

    Car(Frame*, Engine*, Battery*, Colour);
    ~Car();
private:
    Frame* itsFrame_;
    Engine* itsEngine_;
    Battery* itsBattery_;
    Colour itsColour_;
};

#endif
