#include "../include/BaseLane.h"


BaseLane::BaseLane(int space, int travel_time)
    : space_{space}, travel_time_{travel_time}
{
}

bool BaseLane::insertVehicle(Vehicle v) {
    if (v.size() <= space()) {
        in().push(v);
        space_ -= v.size();
        return true;
    }
    return false;
}

int BaseLane::size() {
	return in_.size();
}

void BaseLane::set_space(int space) {
	space_ = space;
}

int BaseLane::space() {
    return space_;
}

int BaseLane::travel_time() {
    return travel_time_;
}

Queue<Vehicle>& BaseLane::in() {
    return in_;
}
