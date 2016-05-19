#include "../include/EventHandler.h"

EventHandler::EventHandler(): num_vehicles_entered_{0}, num_vehicles_exited_{0}
{}

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
        int next_event_time = event.time() +
                              ((std::rand() % (max_time + 1)) + min_time);
        schedule(Event{next_event_time, kSpawnVehicle, event.elementA()});
        std::cout << "Vehicle spawned @" << event.time() << "s\n";
        }
        break;

    // CHANGE_LANE
    case 1:
        {
        //changeLane();
        schedule(Event{event.time() + 5, kChangeLane, event.elementA()});
        }
        break;

    // ARRIVAL
    case 2:
        {
        arrival();
        std::cout << "Vehicle arrived @" << event.time() << "s\n";
        }
        break;

    // CHANGE_SEMAPHORE
    case 3:
        {
        changeSemaphore(event.elementA());
        schedule(Event{event.time() + ((Semaphore *)event.elementA())->getInterval(), kChangeSemaphore, event.elementA()});
        std::cout << "Semaphore lights changed @" << event.time() << "s\n";
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

void EventHandler::spawnVehicle(void* lane, int current_time) {
  int size = std::rand()%6+5;
  if(size <= ((SourceLane *)lane)->space()) {
    ((SourceLane *)lane)->insertVehicle(Vehicle{size, ((SourceLane *)lane)->generateDirection()});
    schedule(Event{((SourceLane *)lane)->travel_time() + current_time, kArrival, lane});
    num_vehicles_entered_++;
  }
}

void EventHandler::changeLane(void *semaphore) {
    std::cerr << "attempting to change lanes\n";
}

void EventHandler::arrival() {
}


void EventHandler::changeSemaphore(void *semaphore) {

}

void EventHandler::report() {
    std::cout << "Cars that entered the system: " << num_vehicles_entered_ << "\n";
    std::cout << "Cars that exited the system: " << num_vehicles_exited_ << "\n";
}