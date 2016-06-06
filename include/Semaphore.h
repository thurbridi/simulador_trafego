#ifndef SEMAPHORE_H
#define SEMAPHORE_H

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

    void setLanes(BaseLane *north, BaseLane *east, BaseLane *south, BaseLane *west);

    void changeState();

    BaseLane* free_lane();

    int interval();

 private:
    int interval_;
    ArrayList<BaseLane*> lane_list_;
    SemaphoreState state_;
};

#endif
