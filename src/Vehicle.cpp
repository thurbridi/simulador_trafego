#include "../include/Vehicle.h"


Vehicle::Vehicle(int size)
    : size_{size}, destination_{nullptr}
{}

Vehicle::Vehicle(int size, BaseLane* destination)
    : size_{size}, destination_{destination}
{}

int Vehicle::size() const {
    return size_;
}

BaseLane* Vehicle::destination() const {
    return destination_;
}

