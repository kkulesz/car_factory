#include "car.h"

Car::Car( Frame* newFrame ,Engine* newEngine, Battery* newBattery, Colour colour):
    itsFrame_(newFrame),itsEngine_(newEngine), itsBattery_(newBattery), itsColour_(colour){}

Car::~Car(){
    delete itsFrame_;
    delete itsEngine_;
    delete itsBattery_;
}

