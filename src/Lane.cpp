#include "../include/Lane.h"


Lane::Lane(int space, int travel_time)
    : in_{}, out_{}, space_{space}, travel_time_{travel_time}
{
}

void Lane::setDestinations(std::pair<Lane*, int> front,
                           std::pair<Lane*, int> left,
                           std::pair<Lane*, int> right) {
    lanes_.insert(kFront, front);
    lanes_.insert(kLeft, left);
    lanes_.insert(kRight, right);
}

void Lane::arrival() { out_.push(in_.pop()); }

void Lane::insertVehicle(const Vehicle& v) {
    in_.push(Vehicle{v.size(), generateDirection()});
    space_ -= v.size();
}

bool Lane::moveVehicle() {
    Vehicle v = out_.front();
    Lane* dest = lanes_.at(v.direction()).first;
    if (dest->space() < v.size()) {
        return false;
    }
    dest->insertVehicle(out_.pop());
    space_ += v.size();
    return true;
}

Direction Lane::generateDirection() const {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0,99);
    int turn = dist(rd);
    if (turn < lanes_.at(kFront).second) {
        return kFront;
    }
    if (turn < lanes_.at(kLeft).second) {
        return kFront;
    }
    if (turn < lanes_.at(kRight).second) {
        return kRight;
    }
    return kExit;    // not sure if we need this one
}

int Lane::space() const {
    return space_;
}

int Lane::travel_time() const {
    return travel_time_;
}
