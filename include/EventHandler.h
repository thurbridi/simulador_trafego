#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structures/List.hpp"
#include "Event.h"
#include "ConsumerLane.h"
#include "SourceLane.h"
#include "Semaphore.h"


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

    Direction generateDirection(BaseLane* lane);

    int nextSpawnTime(SourceLane* lane);

 private:
    List<Event> event_list_;
    Event current_;
};

#endif
