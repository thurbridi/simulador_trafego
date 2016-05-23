#include "../include/NonConsumerLane.h"


NonConsumerLane::NonConsumerLane(int space, int travel_time)
    : BaseLane{space, travel_time},
      destination_list_{3}
{}

void NonConsumerLane::setDestinations(std::pair<BaseLane*, int> front,
                                      std::pair<BaseLane*, int> left,
                                      std::pair<BaseLane*, int> right) {
    destination_list_.insert(kFront, front);
    destination_list_.insert(kLeft, left);
    destination_list_.insert(kRight, right);
}

void NonConsumerLane::arrival() {
    out_.push(in().pop());
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
    dest->insertVehicle(out_.pop());
    return true;
}

Vehicle NonConsumerLane::firstVehicle() {
    return out_.front();
}

bool NonConsumerLane::ready() {
    return !out_.empty();
}

BaseLane* NonConsumerLane::destination() {
    int chance = generate(0, 99);
    if (chance < destination_list_.at(kFront).second) {
        return destination_list_.at(kFront).first;
    }
    if (chance < destination_list_.at(kLeft).second) {
        return destination_list_.at(kLeft).first;
    }
    return destination_list_.at(kRight).first;
}

int NonConsumerLane::generate(int low, int high) {
    return low + generator_() % (high - low);
}

Queue<Vehicle>& NonConsumerLane::out() {
    return out_;
}