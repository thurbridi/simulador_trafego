#ifndef CENTER_LANE_H
#define CENTER_LANE_H


#include "NonConsumerLane.h"
#include "Vehicle.h"


class CenterLane : public NonConsumerLane {
 public:
    using NonConsumerLane::NonConsumerLane;

    bool insertVehicle(const Vehicle& v);
};

#endif
