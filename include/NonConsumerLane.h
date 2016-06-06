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
     NonConsumerLane(int space, int travel_time);

     ~NonConsumerLane();



     void arrival() override;

     bool moveVehicle();

     void setDestinations(std::pair<BaseLane*, int> front,
                          std::pair<BaseLane*, int> left,
                          std::pair<BaseLane*, int> right);



     const Vehicle& first_vehicle() const;

     bool ready() const;

     int size() const override;

 protected:
     BaseLane* destination();

     int generate(int low, int high);

     const Queue<Vehicle>& out() const;
     Queue<Vehicle>& out();
     
 private:
    Queue<Vehicle> out_;
    ArrayList<std::pair<BaseLane*, int>> destination_list_;

    std::random_device generator_;
};

#endif
