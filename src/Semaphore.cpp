#include "../include/Semaphore.h"


Semaphore::Semaphore(int interval)
    : interval_{interval}, state_{kNorth}, lane_list_{4}
{}

void Semaphore::setLanes(BaseLane *north, BaseLane *east, BaseLane *south, BaseLane *west) {
    lane_list_.insert(kNorth, north);
    lane_list_.insert(kEast, east);
    lane_list_.insert(kSouth, south);
    lane_list_.insert(kWest, west);
}

void Semaphore::changeState() {
    state_ = SemaphoreState((state_ + 1) % 4);
}

BaseLane* Semaphore::free_lane() {
    return lane_list_.at(state_);
}

int Semaphore::interval() {
    return interval_;
}
