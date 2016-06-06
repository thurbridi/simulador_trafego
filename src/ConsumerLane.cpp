#include "../include/ConsumerLane.h"


bool ConsumerLane::insertVehicle(Vehicle v) {
    return BaseLane::insertVehicle(Vehicle{v.size(), nullptr});
}

void ConsumerLane::arrival() {
	int new_space = space() + in().pop().size();
	set_space(new_space);
    ++exited_;
}

int ConsumerLane::exited() {
    return exited_;
}
