#ifndef _CAR_FACTORY_H_
#define _CAR_FACTORY_H_

#include "frame_factory.h"
#include "engine_factory.h"
#include "battery_factory.h"
#include "warehouse.h"

class CarFactory: public Factory{
public:
    CarFactory(){};
private:
    FrameFactory frameFactory_;
    EngineFactory engineFactory_;
    BatteryFactory batteryFactory_;
    Warehouse warehouse_;
};

#endif
