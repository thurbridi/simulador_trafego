#include "../include/CenterLane.h"


bool CenterLane::insertVehicle(Vehicle v) {
    return BaseLane::insertVehicle({v.size(), destination()});
}
