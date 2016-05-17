#include <iostream>

#include "../include/System.h"
#include "../include/Lane.h"
#include "../include/ConsumerLane.h"
#include "../include/SourceLane.h"

System::System(int simulation_time, int semaphore_time):
    simulation_time_{simulation_time},
    semaphore_time_{semaphore_time}
{}

System::~System() {}

void System::setUp() {
    // Create lanes
    SourceLane* N1sul = new SourceLane{500, 30, 20, 5};
    ConsumerLane* N1norte = new ConsumerLane{500, 30};

    SourceLane* N2sul = new SourceLane{500, 45, 20, 5};
    ConsumerLane* N2norte = new ConsumerLane{500, 45};

    SourceLane* L1oeste = new SourceLane{400, 48, 10, 2};
    ConsumerLane* L1leste = new ConsumerLane{400, 48};

    SourceLane* S2norte = new SourceLane{500, 45, 60, 15};
    ConsumerLane* S2sul = new ConsumerLane{500, 45};

    SourceLane* S1norte = new SourceLane{500, 30, 30, 7};
    ConsumerLane* S1sul = new ConsumerLane{500, 30};

    SourceLane* O1leste = new SourceLane{2000, 90, 10, 2};
    ConsumerLane* O1oeste = new ConsumerLane{2000, 90};

    Lane* C1oeste = new Lane{300, 18};
    Lane* C1leste = new Lane{300, 18};

    // Connect lanes with eachother
    N1sul->setDestinations(S1sul, C1leste, O1oeste);

    N2sul->setDestinations(S2sul, L1leste, C1oeste);

    L1oeste->setDestinations(C1oeste, S2sul, N2norte);

    S2norte->setDestinations(N2norte, C1oeste, L1leste);

    S1norte->setDestinations(N1norte, O1oeste, C1leste);

    O1leste->setDestinations(C1leste, N1norte, S1sul);

    C1oeste->setDestinations(O1oeste, S1sul, N1norte);
    C1leste->setDestinations(L1leste, N2norte, S2sul);

    // Create Semaphores
    Semaphore* S1 = new Semaphore{semaphore_time_};
    Semaphore* S2 = new Semaphore{semaphore_time_};

    // Create first events
    // TODO
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
    while (handler_.n_of_events() > 0 && event_time <= simulation_time_) {
        event_time = handler_.processNextEvent();
    }
}

void System::showResults() {
    std::cout << "Simulation time: " << simulation_time_ << " seconds\n";
    std::cout << "Cars that entered the system: " << "\n"; // still needs data
    std::cout << "Cars that exited the system: " << "\n"; // still needs data
}