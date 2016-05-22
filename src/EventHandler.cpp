#include "../include/EventHandler.h"

EventHandler::EventHandler(): num_vehicles_entered_{0}, num_vehicles_exited_{0}
{}

void EventHandler::processNextEvent() {
    current_ = event_list_.popFront();
    switch (current_.type()) {
    // SPAWN_VEHICLE
    case 0:

    // CHANGE_LANE
    case 1:

    // ARRIVAL
    case 2:

    // CHANGE_SEMAPHORE
    case 3:
    }
}


void EventHandler::schedule(const Event& event) {
    event_list_.insert(event);
}

int EventHandler::n_of_events() {
    return event_list_.size();
}

void EventHandler::spawnVehicle(SourceLane* lane) {
    Vehicle v{lane->generateDirection()};
    if (lane->space() >= v.size()) {
        lane->insertVehicle(v);
    }
    Event next{current_.time() + lane->generateSpawnTime(),
               kSpawnVehicle,
               (void*) lane};
    schedule(next);
}

void EventHandler::changeLane(Semaphore* sem) {
    Lane* free_lane = sem->freeLane();
    while (free_lane->moveVehicle()) {
        // do nothing
    }
    Event next{current_.time() + sem->interval(), kChangeLane, (void*) sem};
    schedule(next);
}

void EventHandler::arrival(Lane* v) {
    v->arrival();
}


void EventHandler::changeSemaphore(Semaphore* sem) {
    sem->changeState();
}

void EventHandler::report() {
    std::cout << "Cars that entered the system: " << num_vehicles_entered_ << "\n";
    std::cout << "Cars that exited the system: " << num_vehicles_exited_ << "\n";
}