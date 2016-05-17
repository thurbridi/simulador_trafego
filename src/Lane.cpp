#include "../include/Lane.h"


Lane::Lane(int space, int travel_time)
    : Queue::Queue{},
      space_{space},
      travel_time_{travel_time}
{
}

void Lane::setDestinations(Lane* front, Lane* left, Lane* right) {
    lanes_.insert(kFront, front);
    lanes_.insert(kLeft, left);
    lanes_.insert(kRight, right);
}

void Lane::insertVehicle(const Vehicle& v) {
    push(Vehicle{v.size(), generateDirection()});
    space_ -= v.size();
}

Direction generateDirection() {
    std::uniform_int_distribuition<int> dist{1, 100};
    int chance = dist(rd_);
    for (int i = 0; i < turn_chance_.size(); ++i) {
      if (chance <= turn_chance_.at(i)) {
        return (Direction) i;
      }
    }
}

bool Lane::moveVehicle() {
    Vehicle v = front();
    Lane* dest = lanes_.at(v.direction());
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
