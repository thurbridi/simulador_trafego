#ifndef CONSUMER_LANE_H
#define CONSUMER_LANE_H


#include "BaseLane.h"
#include "Vehicle.h"


class ConsumerLane : public BaseLane {
 public:
    ConsumerLane(int space, int travel_time);

    ~ConsumerLane();



    void arrival() override;

 	bool insertVehicle(const Vehicle& v);



    int exited() const;

    int size() const override;

 private:
    int exited_;
};

#endif
