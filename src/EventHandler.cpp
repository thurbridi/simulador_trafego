#include "../include/EventHandler.h"


void EventHandler::schedule(const Event& e) {
    event_list_.insert(e);
}

void EventHandler::spawnVehicle() {
    std::cout << "vehicle spawned\n";
}

void EventHandler::changeLane() {
    std::cout << "attempting to change lanes\n";
}

void EventHandler::removeVehicle() {
    std::cout << "vehicle removed\n";
}

void EventHandler::changeSemaphore() {
    std::cout << "semaphore lights changed\n";
}

void EventHandler::processEvent(const Event& e) {
  switch (e.getType()) {
    // SPAWN_VEHICLE
    case 0:
      spawnVehicle();
      schedule(Event(e.getTime + 10, kSpawnVehicle, nullptr));
      schedule(Event(e.getTime + 5, kArrival, nullptr));
      break;

    // CHANGE_LANE
    case 1:
      changeLane();
      break;

    // REMOVE_VEHICLE
    case 2:
      removeVehicle();
      break;

    // CHANGE_SEMAPHORE
    case 3:
      changeSemaphore();
      break;
  }
}
