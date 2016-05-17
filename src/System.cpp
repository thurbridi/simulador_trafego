#include <iostream>

#include "../include/System.h"
#include "../include/ConsumerLane.h"
#include "../include/SourceLane.h"

System::System(int simulation_time, int semaphore_time):
    simulation_time_{simulation_time},
    semaphore_time_{semaphore_time}
{}

System::~System() {}

void System::setUp() {
    Semaphore* s = new Semaphore{semaphore_time_};
    handler_.schedule(Event{0, kChangeSemaphore, (void*) s});

    SourceLane* left = new SourceLane{2000, 90, 0, 0};
    handler_.schedule(Event{0, kSpawnVehicle, (void*) left});

    ConsumerLane* right = new ConsumerLane{400, 48};



    left->setDestinations(right);
    lane_.pushBack(left);
    lane_.pushBack(right);
    s->setLanes(nullptr, left, nullptr, right);
    sem_.pushBack(s);
}

void System::run() {
    int event_time = 0;
    while (handler_.n_of_events() > 0 && event_time <= simulation_time_) {   // this 60 represents the running time of simulation
        event_time = handler_.processNextEvent();
    }
}

void System::showResults() {
    std::cout << "cars got in and out, yay!\n";
}