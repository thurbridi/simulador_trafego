#ifndef CENTERLANE_H_
#define CENTERLANE_H_

#include "NonConsumerLane.h"


class CenterLane : public NonConsumerLane {
 public:
    using NonConsumerLane::NonConsumerLane;

    bool insertVehicle(Vehicle v);
};

#endif