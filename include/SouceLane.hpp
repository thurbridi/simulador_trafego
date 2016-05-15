#ifndef SOURCELANE_HPP
#define SOURCELANE_HPP

#include "Lane.hpp"

class SourceLane : public Lane {
 public:
     SourceLane(int space, int travel_time, int base_frequency, int variation)
         : Lane::Lane{space, travel_time},
           base_frequency_{base_frequency},
           variation_{variation}
     {}

     void spawnVehicle() {
         int size = generate(2, 6);
         Destination dest = (Destination) generate(0, 3);
         push(Vehicle{size, dest});
     }

     int base_frequency() const { return base_frequency_; }
     int variation() const { return variation_; }

 private:
    int base_frequency_;
    int variation_;
};

#endif
