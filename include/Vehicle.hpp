#ifndef VEHICLE_HPP_
#define VEHICLE_HPP_

#include "TrafficEnum.hpp"

class Vehicle {
public:
    Vehicle(int size, Destination destination)
        : size_{size + 3}, destination_{destination}, arrived_{false}
    {}

    int size() const { return size_; }

    Destination destination() const { return destination_; }

    bool arrived() const { return arrived_; }

    void set_arrived() { arrived_ = true; }

private:
    int size_;
    Destination destination_;
    bool arrived_;
};


#endif