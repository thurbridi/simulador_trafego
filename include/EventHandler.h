#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

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

    void processNextEvent();

    void schedule(Event e);

    void changeSemaphore(Semaphore* semaphore);

    void spawnVehicle(SourceLane* lane);

    void arrival(BaseLane* lane);

    void changeLane(Semaphore* sem);
    
    Event next_event();

    int current_time();

    int generateSize();

    Direction generateDirection(Lane* lane);

    int nextSpawnTime(SourceLane* lane);

 private:
    List<Event> event_list_;
    Event current_;
    std::random_device generator_;
};

#endif
