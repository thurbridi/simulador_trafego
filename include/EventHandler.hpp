#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <iostream>

class EventHandler {
 private:
  void spawnVehicle() {
    std::cout << "vehicle spawned\n";
  }

  void changeLane() {
    std::cout << "attempting to change lanes\n";
  }

  void removeVehicle() {
    std::cout << "vehicle removed\n";
  }

  void changeSemaphore() {
    std::cout << "semaphore lights changed\n";
  }

 public:
  EventHandler();

  ~EventHandler();

  void processEvent(Event event) {
    switch (event.getType()) {
      // SPAWN_VEHICLE
      case 0:
        spawnVehicle();
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



};

#endif
