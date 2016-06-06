#ifndef CONSUMER_LANE_H
#define CONSUMER_LANE_H

#include "BaseLane.h"


class ConsumerLane : public BaseLane {
 public:
    ConsumerLane(int space, int travel_time);

    ~ConsumerLane();



    void arrival() override;

 	bool insertVehicle(Vehicle v);



    int exited() const;

    int size() const override;

 private:
    int exited_;
};

#endif
