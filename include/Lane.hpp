#ifndef LANE_HPP
#define LANE_HPP

#include <random>
#include "structures/Queue.hpp"
#include "Vehicle.hpp"

class Lane : protected Queue<Vehicle> {
 public:
     Lane(int space, int travel_time)
         : Queue::Queue{},
           space_{space},
           travel_time_{travel_time}
     {}

     void insertVehicle(const Vehicle& v) {
         Destination dest = (Destination) generate(0, 3);
         push(Vehicle{v.size(), dest});
     }

     int space() const { return space_; }

     int travel_time() const { return travel_time_; }

 protected:
     int generate(int low, int high) {
         std::random_device rd;
         std::uniform_int_distribution<int> generator(low, high);
         return generator(rd);
     }

 private:
    int space_;
    int travel_time_;
};

#endif
