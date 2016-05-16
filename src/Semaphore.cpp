#include "../include/Semaphore.h"

#include "../include/ConsumerLane.h"
#include "../include/SourceLane.h"
#include "../include/TrafficEnum.h"

Semaphore::Semaphore(int time, Lane* lane) : time_{time}, state_{kWest} {
    lane_.pushFront(lane);
}

void Semaphore::changeState() {
    state_ = SemaphoreState((state_ + 1) % 4);
}

int Semaphore::time() const {
    return time_;
}