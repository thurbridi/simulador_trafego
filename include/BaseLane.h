#ifndef BASELANE_H_
#define BASELANE_H_

#include "structures/Queue.hpp"
#include "Vehicle.h"


class BaseLane {
 public:
     // constructors:
     BaseLane(int space, int travel_time);

     // modifying members:
     bool insertVehicle(Vehicle v);
     virtual void arrival() = 0;
     
     // nonmodifying members:
     int space();
     int travel_time();

 protected:
     Queue<Vehicle>& in();
     
 private:
    int space_;
    int travel_time_;
    Queue<Vehicle> in_;
};

#endif
