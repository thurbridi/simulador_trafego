#ifndef BASE_LANE_H
#define BASE_LANE_H


#include "structures/Queue.hpp"
#include "Vehicle.h"


class Vehicle;    // forward declaration

class BaseLane {
 public:
	 BaseLane(int space, int travel_time);

     virtual ~BaseLane();



     virtual void arrival() = 0;

     virtual bool insertVehicle(const Vehicle& v);
     
     void decrease_space(int space);

     void increase_space(int space);



     virtual int size() const = 0;

     int space() const;

     int travel_time() const;

 protected:
     Queue<Vehicle>& in();

     const Queue<Vehicle>& in() const;
     
 private:
     int space_;

     int travel_time_;

     Queue<Vehicle> in_;
};

#endif
