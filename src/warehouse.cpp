#include "warehouse.h"

Warehouse::~Warehouse(){
    clearList_( frames_ );
    clearList_( engines_ );
    clearList_( batteries_ );
    clearList_( cars_ );

}

void Warehouse::addFrame( Frame* newFrame ){
    frames_.push_front(newFrame);
}

void Warehouse::addEngine( Engine* newEngine ){
    engines_.push_front(newEngine);
}

void Warehouse::addBattery( Battery* newBattery ){
    batteries_.push_front(newBattery);
}

void Warehouse::addCar( Car* newCar ){
    cars_.push_front(newCar);
}

Frame* Warehouse::getFrame(){
    Frame* frameToGive = frames_.front();
    frames_.pop_front();
    return frameToGive;
}

Engine* Warehouse::getEngine(){
    Engine* engineToGive = engines_.front();
    engines_.pop_front();
    return engineToGive;
}

Battery* Warehouse::getBattery(){
    Battery* batteryToGive = batteries_.front();
    batteries_.pop_front();
    return batteryToGive;
}

Car* Warehouse::getCar(){
    Car* carToGive = cars_.front();
    cars_.pop_front();
    return carToGive;
}

template<class T>
void Warehouse::clearList_( std::forward_list<T> listToClear ){
    while( !listToClear.empty() ){
        delete listToClear.front();
        listToClear.pop_front();
    }
}

