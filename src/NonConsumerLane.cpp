#include "../include/NonConsumerLane.h"


NonConsumerLane::NonConsumerLane(int space, int travel_time)
    : BaseLane{space, travel_time},
	  out_{},
      destination_list_{3}
{}

NonConsumerLane::~NonConsumerLane() {}

void NonConsumerLane::arrival() {
	if (!in().empty()) {
		out_.push(in().pop());
	}
}

bool NonConsumerLane::moveVehicle() {
    if (out_.empty()) {
        return false;
    }
    Vehicle v = out_.front();
    BaseLane* dest = v.destination();
    if (dest->space() < v.size()) {
        return false;
    }
    decrease_space(v.size());
    dest->insertVehicle(out_.pop());
    return true;
}

void NonConsumerLane::set_destinations(std::pair<BaseLane*, int> front,
                                       std::pair<BaseLane*, int> left,
                                       std::pair<BaseLane*, int> right) {
    destination_list_.insert(kFront, front);
    destination_list_.insert(kLeft, left);
    destination_list_.insert(kRight, right);
}

Vehicle NonConsumerLane::first_vehicle() const {
    return out_.front();
}

bool NonConsumerLane::ready() const {
    return !out_.empty();
}

int NonConsumerLane::size() const {
	return in().size() + out_.size();
}

Queue<Vehicle>& NonConsumerLane::out() {
    return out_;
}

BaseLane* NonConsumerLane::destination() const {
    int chance = generate(0, 99);
    if (chance < destination_list_.at(kFront).second) {
        return destination_list_.at(kFront).first;
    }
    if (chance < destination_list_.at(kLeft).second) {
        return destination_list_.at(kLeft).first;
    }
    return destination_list_.at(kRight).first;
}

int NonConsumerLane::generate(int low, int high) const {
	std::random_device generator;
    return low + generator() % (high - low);
}

const Queue<Vehicle>& NonConsumerLane::out() const {
    return out_;
}
