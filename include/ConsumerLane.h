#ifndef CONSUMERLANE_HPP
#define CONSUMERLANE_HPP

#include "Lane.h"


class ConsumerLane : public Lane {
 public:
    ConsumerLane(int space, int travel_time);

    virtual bool moveVehicle();

 private:
    int vehicle_count_;
};

#endif
