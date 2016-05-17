#include "../include/EventHandler.h"


int EventHandler::processNextEvent() {
    Event e = event_list_.popFront();
    switch (e.type()) {
    // SPAWN_VEHICLE
    case 0:
        spawnVehicle();
        schedule(Event{e.time() + 10, kSpawnVehicle, e.elementA()});
        schedule(Event{e.time() + 5, kArrival, e.elementA()});
        break;

    // CHANGE_LANE
    case 1:
        changeLane();
        schedule(Event{e.time() + 5, kChangeLane, e.elementA()});
        break;

    // REMOVE_VEHICLE
    case 2:
        arrival();
        break;

    // CHANGE_SEMAPHORE
    case 3:
        changeSemaphore();
        schedule(Event{e.time() + 20, kChangeSemaphore, e.elementA()});
        break;
    }

    return e.time();
}


void EventHandler::schedule(const Event& e) {
    event_list_.insert(e);
}

int EventHandler::n_of_events() {
    return event_list_.size();
}

void EventHandler::arrival() {
    std::cerr << "vehicle arrived\n";
}

void EventHandler::changeLane() {
    std::cerr << "attempting to change lanes\n";
}

void EventHandler::changeSemaphore() {
    std::cout << "semaphore lights changed\n";
}

void EventHandler::spawnVehicle() {
    std::cerr << "vehicle spawned\n";
}
