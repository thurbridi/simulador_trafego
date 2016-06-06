#ifndef NONCONSUMERLANE_H_
#define NONCONSUMERLANE_H_

#include <utility>
#include <random>
#include "structures/ArrayList.hpp"
#include "BaseLane.h"

enum Direction {
    kFront,
    kLeft,
    kRight
};

class NonConsumerLane : public BaseLane {
 public:
     // constructors:
     NonConsumerLane(int space, int travel_time);

     // modifying members:
     void setDestinations(std::pair<BaseLane*, int> front,
                          std::pair<BaseLane*, int> left,
                          std::pair<BaseLane*, int> right);
     virtual void arrival();
     bool moveVehicle();

     // nonmodifying members:
     Vehicle firstVehicle();
     bool ready();

 protected:
     BaseLane* destination();
     int generate(int low, int high);
     Queue<Vehicle>& out();
     
 private:
    Queue<Vehicle> out_;
    ArrayList<std::pair<BaseLane*, int>> destination_list_;

    std::random_device generator_;
};

#endif