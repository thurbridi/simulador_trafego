#include "../include/ConsumerLane.h"


ConsumerLane::ConsumerLane(int space, int travel_time)
	: BaseLane{space, travel_time},
	  exited_{0}
{}

ConsumerLane::~ConsumerLane() {}



void ConsumerLane::arrival() {
	increase_space(in().pop().size());
    ++exited_;
}

bool ConsumerLane::insertVehicle(Vehicle v) {
    return BaseLane::insertVehicle(Vehicle{v.size(), nullptr});
}



int ConsumerLane::exited() const {
    return exited_;
}

int ConsumerLane::size() const {
	return BaseLane::in().size();
}
