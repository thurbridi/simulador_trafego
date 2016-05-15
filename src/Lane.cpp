#include "../include/Lane.h"


Lane::Lane(int space, int travel_time)
    : Queue::Queue{},
      space_{space},
      travel_time_{travel_time}
{
    setDestinations(nullptr, nullptr, nullptr);
}

void Lane::setDestinations(Lane* front,
                           Lane* left = nullptr,
                           Lane* right = nullptr) {
    lanes_.insert(kFront, front);
    lanes_.insert(kLeft, left);
    lanes_.insert(kRight, right);
}

void Lane::insertVehicle(const Vehicle& v) {
    // randomize destination
    // push(Vehicle{v.size(), NEWDESTINATION});
    space_ -= v.size();
}

bool Lane::moveVehicle() {
    Vehicle v = front();
    Lane* dest = lanes_.at(v.destination);
    if (dest->space() < v.size()) {
        return false;
    }
    dest->insertVehicle(pop());
    space_ += v.size();
    return true;
}

int Lane::space() const {
    return space_;
}

int Lane::travel_time() const {
    return travel_time_;
}
