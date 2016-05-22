#ifndef LANE_H_
#define LANE_H_

#include <random>
#include "structures/ArrayList.hpp"
#include "structures/Queue.hpp"
#include "Vehicle.h"


class Lane {
 public:
     Lane(int space, int travel_time);

     void setDestinations(std::pair<Lane*, int> front,
                          std::pair<Lane*, int> left,
                          std::pair<Lane*, int> right);

     virtual void arrival();

     virtual bool moveVehicle();

     virtual void insertVehicle(const Vehicle& v);

     virtual Direction generateDirection() const;

     int space() const;

     int travel_time() const;

 protected:
    Queue<Vehicle> in_;
    Queue<Vehicle> out_;
    int space_;
    int travel_time_;

    ArrayList<std::pair<Lane*, int>> lanes_{3};
};

#endif