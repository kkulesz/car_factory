#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include <forward_list>
#include "car.h"

class Warehouse{
public:
    Warehouse(){};
    ~Warehouse();

    void addFrame( Frame* );
    void addEngine( Engine* );
    void addBattery( Battery* );
    void addCar( Car* );

    Frame* getFrame();
    Engine* getEngine();
    Battery* getBattery();
    Car* getCar();

private:
    std::forward_list<Frame*> frames_;
    std::forward_list<Engine*> engines_;
    std::forward_list<Battery*> batteries_;
    std::forward_list<Car*> cars_;

    template<class T>
    void clearList_( std::forward_list<T>);
};

#endif
