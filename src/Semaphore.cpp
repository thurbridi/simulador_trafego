#include "../include/Semaphore.h"

#include "../include/ConsumerLane.h"
#include "../include/SourceLane.h"

Semaphore::Semaphore(int time) : time_{time} {}

void Semaphore::setLanes(Lane *north, Lane *east, Lane *south, Lane *west) {
  lanes_.insert(kNorth, north);
  lanes_.insert(kEast, east);
  lanes_.insert(kSouth, south);
  lanes_.insert(kWest, west);
}

void Semaphore::changeState() {
  state_ = SemaphoreState((state_ + 1) % 4);
}

int Semaphore::time() const {
  return time_;
}