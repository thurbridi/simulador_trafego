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
    int exited();

 private:
    int exited_;
};

#endif
