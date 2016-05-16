#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <iostream>
#include "Event.h"

class EventHandler {
 public:
    void processEvent(const Event& e);

    void schedule(const Event& e);

    void spawnVehicle();

    void changeLane();

    void removeVehicle();

    void changeSemaphore();
};

#endif
