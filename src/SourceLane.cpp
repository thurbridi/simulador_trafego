#include "../include/SourceLane.h"


SourceLane::SourceLane(int space,
                       int travel_time,
                       int base_frequency,
                       int variation)
    : NonConsumerLane{space, travel_time},
      base_frequency_{base_frequency},
      variation_{variation},
	  entered_{0},
	  missed_{0}
{}

bool SourceLane::spawnVehicle() {
    if (insertVehicle(Vehicle{generate(5, 9), destination()})) {
        ++entered_;
        return true;
    }
    ++missed_;
    return false;
}

int SourceLane::spawn_interval() {
    return base_frequency_ + generate(-variation_, variation_);
}

int SourceLane::entered() const {
    return entered_;
}

int SourceLane::missed() const {
    return missed_;
}
