#include <iostream>
#include "factory_manager.h"
int main(){
    FactoryManager manager;
    manager.produceAllParts();
    if(manager.produceCar(Car::BLACK))
        std::cout<<"tu powinienem byc"<<std::endl;
    if(manager.produceCar(Car::BLUE))
        std::cout<<"tu nie powinienem byc"<<std::endl;
    manager.produceAllParts();
    manager.produceBattery();
    manager.produceEngine();
    if(manager.produceCar(Car::BLACK))
        std::cout<<"tu powinienem byc"<<std::endl;
    if(manager.produceCar(Car::BLUE))
        std::cout<<"tu nie powinienem byc"<<std::endl;
}
