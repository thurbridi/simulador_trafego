#include "../include/SourceLane.h"


SourceLane::SourceLane(int space,
                       int travel_time,
                       int base_frequency,
                       int variation)
    : Lane::Lane{space, travel_time},
      base_frequency_{base_frequency},
      variation_{variation}
{}

void SourceLane::spawnVehicle() {
std::uniform_int_distribuition<int> dist{5, 9};
    int size  = dist(rd_);
    if (size <= space()) {
      insertVehicle(Vehicle{size, generateDirection()});
    }
}

int SourceLane::base_frequency() const {
    return base_frequency_;
}

int SourceLane::variation() const {
    return variation_;
}
