#ifndef _FACTORY_MANAGER_H_
#define _FACTORY_MANAGER_H_

#include "frame_factory.h"
#include "engine_factory.h"
#include "battery_factory.h"
#include "car_factory.h"
#include "warehouse.h"

class FactoryManager{
public:

private:
    Warehouse itsWarehouse_;
    FrameFactory itsFrameFactory_;
    EngineFactory itsEngineFactory_;
    BatteryFactory itsBatteryFactory_;
    CarFactory itsCarFactory_;

};

#endif
