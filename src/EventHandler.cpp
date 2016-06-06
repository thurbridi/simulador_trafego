#include "../include/EventHandler.h"


EventHandler::EventHandler() {}

void EventHandler::processNextEvent() {
    current_ = event_list_.popFront();

    switch (current_.type()) {
    case kArrival:
        arrival((BaseLane*)current_.source());
        break;

    case kChangeSemaphore:
        changeSemaphore((Semaphore*)current_.source());
        break;

    case kChangeLane:
        changeLane((Semaphore*)current_.source());
        break;

    case kSpawnVehicle:
        spawnVehicle((SourceLane*)current_.source());
        break;
    }
}

void EventHandler::schedule(Event event) {
    event_list_.insert(event);
}

void EventHandler::arrival(BaseLane* lane) const {
    lane->arrival();
}

void EventHandler::changeSemaphore(Semaphore* sem) {
    sem->changeState();
    int next_change = current_time() + sem->interval();
    schedule(Event{next_change, kChangeSemaphore, sem});
}

void EventHandler::changeLane(Semaphore* sem) {
    NonConsumerLane* source = (NonConsumerLane*)sem->free_lane();

    bool changed = true;
    while (source->ready() && changed) {
        BaseLane* dest = source->first_vehicle().destination();
        changed = source->moveVehicle();
        if (changed) {
            int arrival_time = current_time() + dest->travel_time();
            schedule(Event{arrival_time, kArrival, dest});
        }
    }
    int next_try_time = current_time() + 2;
    schedule(Event{next_try_time, kChangeLane, sem});
}

void EventHandler::spawnVehicle(SourceLane* lane) {
    if (lane->spawnVehicle()) {
    	int arrival_time = current_time() + lane->travel_time();
    	schedule(Event{arrival_time, kArrival, lane});
    }
    int next_spawn_time = current_time() + lane->spawn_interval();
    schedule(Event{next_spawn_time, kSpawnVehicle, lane});
}

Event EventHandler::next_event() const {
    return event_list_.front();
}

int EventHandler::current_time() const {
    return current_.time();
}
