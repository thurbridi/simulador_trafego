#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <iostream>
#include "Event.h"
#include "structures/List.hpp"


class EventHandler {
 public:
    int processNextEvent();

    void schedule(const Event& e);

    int n_of_events();

    void spawnVehicle(SourceLane* lane);

    void changeLane();

    void arrival();

    void changeSemaphore();

 private:
    List<Event> event_list_;
};

#endif
