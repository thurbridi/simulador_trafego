#include "../include/EventHandler.h"

int EventHandler::processNextEvent() {
    Event event = event_list_.popFront();
    switch (event.type()) {
    // SPAWN_VEHICLE
    case 0:
        {
        spawnVehicle(event.elementA(), event.time());
        int max_time = ((SourceLane *)event.elementA())->base_frequency() +
                       ((SourceLane *)event.elementA())->variation();
        int min_time = ((SourceLane *)event.elementA())->base_frequency() -
                       ((SourceLane *)event.elementA())->variation();
        int next_event_time = event.time() + ((std::rand() % (max_time + 1)) + min_time);
        schedule(Event{next_event_time, kSpawnVehicle, event.elementA()});
        std::cout << "Vehicle spawned @" << event.time() << std::endl;
        }
        break;

    // CHANGE_LANE
    case 1:
        {
        // changeLane();
        // schedule(Event{event.time() + 5, kChangeLane, event.elementA()});
        break;
        }

    // REMOVE_VEHICLE
    case 2:
        {
        arrival();
        std::cout << "Vehicle arrived @" << event.time() << std::endl;
        }
        break;

    // CHANGE_SEMAPHORE
    case 3:
        {
        // changeSemaphore();
        schedule(Event{event.time() + 20, kChangeSemaphore, event.elementA()});
        }
        break;
    }

    return event.time();
}


void EventHandler::schedule(const Event& event) {
    event_list_.insert(event);
}

int EventHandler::n_of_events() {
    return event_list_.size();
}

void EventHandler::arrival() {
}

void EventHandler::changeLane(void *semaphore) {
    // enquanto
    std::cerr << "attempting to change lanes\n";
}

void EventHandler::changeSemaphore(void *semaphore) {
    // troca o sinal
    // reagenda troca de sinal
    std::cout << "semaphore lights changed\n";
}

void EventHandler::spawnVehicle(void* lane, int current_time) {
  std::srand(std::time(nullptr));
  int size = std::rand()%6+5;
  if(size <= ((SourceLane *)lane)->space()) {
    ((SourceLane *)lane)->insertVehicle(Vehicle{size, ((SourceLane *)lane)->generateDirection()});
    schedule(Event{((SourceLane *)lane)->travel_time() + current_time, kArrival, lane});
  }
}
