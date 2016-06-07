#include "../include/BaseLane.h"


BaseLane::BaseLane(int space, int travel_time)
    : space_{space},
	  travel_time_{travel_time},
	  in_{}
{}

BaseLane::~BaseLane() {}

bool BaseLane::insertVehicle(const Vehicle& v) {
	if (space() < v.size()) {
		return false;
	}
	in_.push(v);
	space_ -= v.size();
	return true;
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

Queue<Vehicle>& BaseLane::in() {
    return in_;
}

const Queue<Vehicle>& BaseLane::in() const {
    return in_;
}
