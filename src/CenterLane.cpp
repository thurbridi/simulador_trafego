#include "../include/CenterLane.h"


bool CenterLane::insertVehicle(const Vehicle& v) {
    return BaseLane::insertVehicle({v.size(), destination()});
}
