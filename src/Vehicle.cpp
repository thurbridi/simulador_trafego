#include <random>
#include "../include/Vehicle.h"
#include "../include/System.h"


Vehicle::Vehicle(Direction direction)
    : direction_{direction}
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(2,6);
    size_ = dist(rd);
}

Vehicle::Vehicle(int size, Direction direction)
    : size_{size}, direction_{direction}
{}

int Vehicle::size() const {
    return size_;
}

Direction Vehicle::direction() const {
    return direction_;
}

