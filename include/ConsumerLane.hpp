#ifndef CONSUMERLANE_HPP
#define CONSUMERLANE_HPP

#include "Lane.hpp"


class ConsumerLane : protected Lane {
 public:
     ConsumerLane(int space, int travel_time)
         : Lane::Lane{space, travel_time}, vehicle_count_{0}
     {}

 private:
    int vehicle_count_;
};

#endif
