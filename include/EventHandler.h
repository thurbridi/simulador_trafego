#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Event.h"
#include "Lane.h"
#include "SourceLane.h"
#include "structures/List.hpp"

class EventHandler {
 public:
    int processNextEvent();

    void schedule(const Event& e);

    int n_of_events();

    void spawnVehicle(void* lane, int current_time);

    void changeLane(void* semaphore);

    void arrival();

    void changeSemaphore(void *semaphore);

 private:
    List<Event> event_list_;
};

#endif
