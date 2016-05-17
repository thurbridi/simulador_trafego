#ifndef LANE_H_
#define LANE_H_

#include "structures/ArrayList.hpp"
#include "structures/Queue.hpp"
#include "Vehicle.h"


class Lane : protected Queue<Vehicle> {
 public:
     Lane(int space, int travel_time);

     void setDestinations(Lane* front,
                          Lane* left = nullptr,
                          Lane* right = nullptr);

     virtual bool moveVehicle();

     virtual void insertVehicle(const Vehicle& v);

     int space() const;

     int travel_time() const;

 private:
    int space_;
    int travel_time_;
    ArrayList<Lane*> lanes_{3};
};

#endif