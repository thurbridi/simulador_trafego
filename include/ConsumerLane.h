#ifndef CONSUMERLANE_HPP
#define CONSUMERLANE_HPP

#include "Lane.h"


class ConsumerLane : protected Lane {
 public:
     ConsumerLane(int space, int travel_time);

 private:
    int vehicle_count_;
};

#endif
