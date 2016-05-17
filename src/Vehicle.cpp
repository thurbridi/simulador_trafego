#include "../include/Vehicle.h"


Vehicle::Vehicle(int size, Direction direction)
    : size_{size + 3}, direction_{direction}, arrived_{false}
{
}

int Vehicle::size() const {
    return size_;
}

Direction Vehicle::direction() const {
    return direction_;
}

bool Vehicle::arrived() const {
    return arrived_;
}

void Vehicle::set_arrived() {
    arrived_ = true;
}
