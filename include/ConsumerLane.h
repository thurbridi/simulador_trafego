#ifndef CONSUMERLANE_HPP
#define CONSUMERLANE_HPP

#include "BaseLane.h"


class ConsumerLane : public BaseLane {
 public:
    // constructors:
    using BaseLane::BaseLane;

    // modifying members:
    bool insertVehicle(Vehicle v);
    virtual void arrival();

    // nonmodifying members:
    int vehicle_count();

 private:
    int vehicle_count_;
};

#endif
