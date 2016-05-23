#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include "structures/ArrayList.hpp"
#include "BaseLane.h"


enum SemaphoreState {
    kNorth,
    kEast,
    kSouth,
    kWest
};

class Semaphore {
 public:
    Semaphore(int interval);

    void set_lanes(BaseLane *north, BaseLane *east, BaseLane *south, BaseLane *west);

    void change_state();

    BaseLane* free_lane();

    int interval();

 private:
    int interval_;
    ArrayList<BaseLane*> lane_list_;
    SemaphoreState state_;
};

#endif
