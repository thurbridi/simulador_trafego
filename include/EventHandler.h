#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <iostream>
#include "Event.h"
#include "structures/List.hpp"

class EventHandler {
 public:
    void processEvent(const Event& e);

    void schedule(const Event& e);

    void spawnVehicle();

    void changeLane();

    void arrival();

    void changeSemaphore();

 private:
    List<Event> event_list_;
};

#endif
