#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H


#include "structures/List.hpp"
#include "Event.h"
#include "BaseLane.h"
#include "Semaphore.h"
#include "SourceLane.h"


class EventHandler {
 public:
    EventHandler();

    void changeLane(Semaphore* sem);

    void changeSemaphore(Semaphore* semaphore);

    void processNextEvent();

    void schedule(Event e);

    void spawnVehicle(SourceLane* lane);

    

    void arrival(BaseLane* lane) const;

    int current_time() const;

    Event next_event() const;

 private:
    List<Event> event_list_;
    Event current_;
};

#endif
