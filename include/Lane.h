#ifndef LANE_H_
#define LANE_H_

#include <random>
#include "structures/ArrayList.hpp"
#include "structures/Queue.hpp"
#include "Vehicle.h"


class Lane : protected Queue<Vehicle> {
 public:
     Lane(int space, int travel_time);

     void setDestinations(Lane* front,
                          Lane* left,
                          Lane* right);

     virtual bool moveVehicle();

     virtual void insertVehicle(const Vehicle& v);

     Direction generateDirection();

     int space() const;

     int travel_time() const;

 private:
    int space_;
    int travel_time_;
    ArrayList<Lane*> lanes_{3};

    ArrayList<int> turn_chance_{3};
    std::random_device rd_;
};

#endif