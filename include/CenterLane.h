#ifndef CENTER_LANE_H
#define CENTER_LANE_H


#include "NonConsumerLane.h"
#include "Vehicle.h"


/**
 * @brief      { class_description }
 */
class CenterLane : public NonConsumerLane {
 public:
    using NonConsumerLane::NonConsumerLane;

    /**
     * @brief      { function_description }
     *
     * @param[in]  v     { parameter_description }
     *
     * @return     { description_of_the_return_value }
     */
    bool insertVehicle(const Vehicle& v);
};

#endif
