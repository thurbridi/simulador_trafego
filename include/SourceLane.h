#ifndef SOURCE_LANE_H
#define SOURCE_LANE_H

#include "NonConsumerLane.h"


class SourceLane : public NonConsumerLane {
 public:
     // constructors:
     SourceLane(int space, int travel_time, int base_frequency, int variation);

     bool spawnVehicle();

     // nonmodifying members:
     int spawn_interval();
     int entered();
     int missed();

 private:
     int base_frequency_;
     int variation_;
     int entered_;
     int missed_;
};

#endif
