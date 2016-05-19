#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Event.h"
#include "Lane.h"
#include "SourceLane.h"
#include "Semaphore.h"
#include "structures/List.hpp"

class EventHandler {
 public:
    EventHandler();

    int n_of_events();

    int processNextEvent();

    void schedule(const Event& e);

    void spawnVehicle(void* lane, int current_time);

    void changeLane(void* semaphore);

    void arrival();

    void changeSemaphore(void *semaphore);

    void report();

 private:
    List<Event> event_list_;
    int num_vehicles_entered_,
        num_vehicles_exited_;
};

#endif
