#include "../include/ConsumerLane.h"


bool ConsumerLane::insertVehicle(Vehicle v) {
    return BaseLane::insertVehicle(Vehicle{v.size, nullptr});
}

void ConsumerLane::arrival() {
    in().pop();
    ++vehicle_count_;
}

int ConsumerLane::vehicle_count() {
    return vehicle_count_;
}
