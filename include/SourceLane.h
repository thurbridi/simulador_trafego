#ifndef SOURCE_LANE_H
#define SOURCE_LANE_H

#include "NonConsumerLane.h"


class SourceLane : public NonConsumerLane {
 public:
     SourceLane(int space, int travel_time, int base_frequency, int variation);

     bool spawnVehicle();

     int spawn_interval();

     int entered() const;

     int missed() const;

 private:
     int base_frequency_;
     int variation_;
     int entered_;
     int missed_;
};

#endif
