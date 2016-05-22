#include "../include/Semaphore.h"

#include "../include/ConsumerLane.h"
#include "../include/SourceLane.h"

Semaphore::Semaphore(int interval)
    : interval_{interval}, lanes_{4}, state_{kNorth}
{}

void Semaphore::setLanes(Lane *north, Lane *east, Lane *south, Lane *west) {
    lanes_.insert(kNorth, north);
    lanes_.insert(kEast, east);
    lanes_.insert(kSouth, south);
    lanes_.insert(kWest, west);
}

void Semaphore::changeState() {
    state_ = SemaphoreState((state_ + 1) % 4);
}

Lane* Semaphore::freeLane() const { return lanes_.at(state_); }

int Semaphore::interval() const {
    return interval_;
}