#include "../include/System.h"

#include <iostream>

System::System(int simulation_time, int semaphore_time)
    : simulation_time_{simulation_time},
      sem_{2},
      source_{6},
      center_{2},
      consumer_{6}
{
    setUp(semaphore_time);
}

System::~System() {}

void System::setUp(int semaphore_time) {
    // Create Semaphores
    Semaphore* S1 = new Semaphore{semaphore_time};    // TODO: change this magic constant
    Semaphore* S2 = new Semaphore{semaphore_time};    // TODO: change this magic constant
    sem_.pushBack(S1);
    sem_.pushBack(S2);
                                          
    // Create source lanes
    SourceLane* N1_south = new SourceLane{ 500, 60, 20,  5};
    SourceLane* N2_south = new SourceLane{ 500, 40, 20,  5};
    SourceLane* E1_west  = new SourceLane{ 400, 30, 10,  2};
    SourceLane* S2_north = new SourceLane{ 500, 40, 60, 15};
    SourceLane* S1_north = new SourceLane{ 500, 60, 30,  7};
    SourceLane* W1_east  = new SourceLane{2000, 80, 10,  2};
    source_.pushBack(N1_south);
    source_.pushBack(N2_south);
    source_.pushBack(E1_west);
    source_.pushBack(S2_north);
    source_.pushBack(S1_north);
    source_.pushBack(W1_east);

    // Create consumer lanes
    ConsumerLane* N1_north = new ConsumerLane{ 500, 60};
    ConsumerLane* N2_north = new ConsumerLane{ 500, 40};
    ConsumerLane* E1_east  = new ConsumerLane{ 400, 30};
    ConsumerLane* S2_south = new ConsumerLane{ 500, 40};
    ConsumerLane* S1_south = new ConsumerLane{ 500, 60};
    ConsumerLane* W1_west  = new ConsumerLane{2000, 80};
    consumer_.pushBack(N1_north);
    consumer_.pushBack(N2_north);
    consumer_.pushBack(E1_east);
    consumer_.pushBack(S2_south);
    consumer_.pushBack(S1_south);
    consumer_.pushBack(W1_west);

    // Create center lanes
    Lane* C1_west = new Lane{300, 60};
    Lane* C1_east = new Lane{300, 60};
    center_.pushBack(C1_west);
    center_.pushBack(C1_east);

    // Attach lanes
    N1_south->setDestinations({S1_south, 10}, { C1_east, 80}, { W1_west, 10});
    N2_south->setDestinations({S2_south, 30}, { E1_east, 40}, { C1_west, 30});
    E1_west->setDestinations( { C1_west, 30}, {S2_south, 30}, {N2_north, 40});
    S2_north->setDestinations({N2_north, 30}, { C1_west, 30}, { E1_east, 40});
    S1_north->setDestinations({N1_north, 10}, { W1_west, 10}, { C1_east, 80});
    W1_east->setDestinations( { C1_east, 80}, {N1_north, 10}, {S1_south, 10});
    C1_west->setDestinations( { W1_west, 40}, {S1_south, 30}, {N1_north, 30});
    C1_east->setDestinations( { E1_east, 40}, {N2_north, 30}, {S2_south, 30});

    // Attach lanes to semaphores
    S1->setLanes(N1_south, C1_west, S1_north, W1_east);
    S2->setLanes(N2_south, E1_west, S2_north, C1_east);

    // Create dummy events
    for (int i = 0; i < sem_.size(); ++i) {
        handler_.schedule({semaphore_time, kChangeSemaphore, sem_.at(i)});
        handler_.schedule({semaphore_time / 5, kChangeLane, sem_.at(i)});
    }

    for (int i = 0; i < source_.size(); ++i) {
        SourceLane* source = source_.at(i);
        handler_.schedule({source->generateSpawnTime(), kSpawnVehicle, source});
    }
}

void System::run() {
    while (handler_.next().time() <= simulation_time_) {
        handler_.processNextEvent();
    }
}

void System::showResults() {
    int entered = 0;
    int exited = 0;
    for (int i = 0; i < source_.size(); ++i) {
        entered += source_.at(i)->
    }
}