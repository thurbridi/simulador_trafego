#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "BaseLane.h"


class Vehicle {
public:
    Vehicle(int size);
    Vehicle(int size, BaseLane* direction);

    int size();
    BaseLane* destination();

private:
    int size_;
    BaseLane* destination_;
};

#endif