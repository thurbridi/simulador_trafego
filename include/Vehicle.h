#ifndef VEHICLE_H
#define VEHICLE_H


#include "BaseLane.h"


class BaseLane;

class Vehicle {
public:
    Vehicle(int size);
    Vehicle(int size, BaseLane* direction);

    int size() const;
    BaseLane* destination() const;

private:
    int size_;

    BaseLane* destination_;
};

#endif
