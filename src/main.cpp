#include <iostream>
#include "factory_manager.h"
int main(){
    Warehouse* mag = new Warehouse();
    Engine* silnik = new Engine();
    mag->addEngine(silnik);
    delete mag;

    std::cout<<"123"<<std::endl;
}
