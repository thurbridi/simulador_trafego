#include "../include/ConsumerLane.h"

ConsumerLane::ConsumerLane(int space, int travel_time)
    : Lane::Lane{space, travel_time}, vehicle_count_{0}
{}

bool ConsumerLane::moveVehicle() {
    space_ += out_.pop().size();
}