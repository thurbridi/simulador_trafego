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

    void processNextEvent();

    void schedule(const Event& e);

    void spawnVehicle(SourceLane* lane);

    void changeLane(Semaphore* sem);

    void arrival(Lane* lane);

    void changeSemaphore(Semaphore* semaphore);

    void report();

 private:
    List<Event> event_list_;
    Event current_;
    int num_vehicles_entered_,
        num_vehicles_exited_;
};

#endif
