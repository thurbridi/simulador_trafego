#include "../include/BaseLane.h"


BaseLane::BaseLane(int space, int travel_time)
    : space_{space}, travel_time_{travel_time}
{}

BaseLane::~BaseLane() {}



bool BaseLane::insertVehicle(Vehicle v) {
    if (v.size() <= space()) {
        in_.push(v);
        space_ -= v.size();
        return true;
    }
    return false;
}

void BaseLane::decrease_space(int space) {
	space_ -= space;
}

void BaseLane::increase_space(int space) {
	space_ += space;
}



int BaseLane::space() const {
    return space_;
}

int BaseLane::travel_time() const {
    return travel_time_;
}

const Queue<Vehicle>& BaseLane::in() const {
    return in_;
}

Queue<Vehicle>& BaseLane::in() {
    return in_;
}
