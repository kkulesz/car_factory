#include "factory_manager.h"

void FactoryManager::produceFrame(){
    itsWarehouse_.addFrame( itsFrameFactory_.produce() );
}

void FactoryManager::produceEngine(){
    itsWarehouse_.addEngine( itsEngineFactory_.produce() );
}

void FactoryManager::produceBattery(){
    itsWarehouse_.addBattery( itsBatteryFactory_.produce() );
}
void FactoryManager::produceAllParts(){
    produceFrame();
    produceEngine();
    produceBattery();
}

bool FactoryManager::produceCar( Car::Colour carColour ){
    if( itsWarehouse_.enoughPartsToProduceCar() ){
        Frame* newFrame = itsWarehouse_.getFrame();
        Engine* newEngine = itsWarehouse_.getEngine();
        Battery* newBattery = itsWarehouse_.getBattery();
        Car* newCar = itsCarFactory_.produce(newFrame, newEngine, newBattery, carColour);
        itsWarehouse_.addCar(newCar);
        return true;
    }else{
        return false;
    }
}
