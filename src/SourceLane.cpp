#include "../include/SourceLane.h"


SourceLane::SourceLane(int space,
                       int travel_time,
                       int base_frequency,
                       int variation)
    : NonConsumerLane{space, travel_time},
      base_frequency_{base_frequency},
      variation_{variation}
{}

void SourceLane::spawnVehicle() {
    if (insertVehicle(Vehicle{generate(5, 9)})) {
        ++entered_;
    } else {
        ++missed_;
    }
}

int SourceLane::spawn_interval() {
    return base_frequency_ + generate(-variation_, variation_);
}

int SourceLane::entered() {
    return entered_;
}

int SourceLane::missed() {
    return missed_;
}