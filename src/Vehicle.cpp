#include "../include/Vehicle.h"


Vehicle::Vehicle(int size, Destination destination)
    : size_{size + 3}, destination_{destination}, arrived_{false}
{
}

int Vehicle::size() const {
    return size_;
}

Destination Vehicle::destination() const {
    return destination_;
}

bool Vehicle::arrived() const {
    return arrived_;
}

void Vehicle::set_arrived() {
    arrived_ = true;
}
