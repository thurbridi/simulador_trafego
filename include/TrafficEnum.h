#ifndef TRAFFICENUM_H_
#define TRAFFICENUM_H_

enum EventType {
    kSpawnVehicle,
    kChangeLane,
    kArrival,
    kChangeSemaphore
};

enum Destination {
    kFront,
    kLeft,
    kRight,
    kExit
};


#endif