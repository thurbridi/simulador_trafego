#include "../include/Semaphore.h"

#include "../include/ConsumerLane.h"
#include "../include/SourceLane.h"

Semaphore::Semaphore(int time) : time_{time} {}

void Semaphore::changeState() {
    state_ = SemaphoreState((state_ + 1) % 4);
}

int Semaphore::time() const {
    return time_;
}