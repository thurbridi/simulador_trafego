#ifndef NON_CONSUMER_LANE_H
#define NON_CONSUMER_LANE_H

#include <random>
#include "structures/ArrayList.hpp"
#include "BaseLane.h"
#include "Vehicle.h"

enum Direction {
    kFront,
    kLeft,
    kRight
};

class NonConsumerLane : public BaseLane {
 public:
     NonConsumerLane(int space, int travel_time);

     ~NonConsumerLane();

     void arrival() override;

     bool moveVehicle();

     void set_destinations(std::pair<BaseLane*, int> front,
                           std::pair<BaseLane*, int> left,
                           std::pair<BaseLane*, int> right);

     Vehicle first_vehicle() const;

     bool ready() const;

     int size() const override;

 protected:
     Queue<Vehicle>& out();

     BaseLane* destination() const;

     int generate(int low, int high) const;

     const Queue<Vehicle>& out() const;

 private:
    Queue<Vehicle> out_;

    ArrayList<std::pair<BaseLane*, int>> destination_list_;
};

#endif
