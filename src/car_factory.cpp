#include "car_factory.h"


Car* CarFactory::produce( Frame* newFrame, Engine* newEngine, Battery* newBattery, Car::Colour itsColour){
    Car* newCar = new Car(newFrame, newEngine, newBattery, itsColour);
    return newCar;
}
