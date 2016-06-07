#include "../include/System.h"


System::System(int simulation_time, int semaphore_time)
    : simulation_time_{simulation_time},
	  semaphore_time_{semaphore_time},
      sem_{2},
      source_{6},
      center_{2},
      consumer_{6}
{
    setUp();
}

System::~System() {}

void System::setUp() {
    // Create Semaphores
    Semaphore* S1 = new Semaphore{semaphore_time_};
    Semaphore* S2 = new Semaphore{semaphore_time_};
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
    CenterLane* C1_west = new CenterLane{300, 60};
    CenterLane* C1_east = new CenterLane{300, 60};
    center_.pushBack(C1_west);
    center_.pushBack(C1_east);

    // Attach lanes
    using dest = std::pair<BaseLane*, int>;
    N1_south->set_destinations(dest{S1_south, 10}, dest{ C1_east, 80}, dest{ W1_west, 10});
    N2_south->set_destinations(dest{S2_south, 30}, dest{ E1_east, 40}, dest{ C1_west, 30});
    E1_west->set_destinations( dest{ C1_west, 30}, dest{S2_south, 30}, dest{N2_north, 40});
    S2_north->set_destinations(dest{N2_north, 30}, dest{ C1_west, 30}, dest{ E1_east, 40});
    S1_north->set_destinations(dest{N1_north, 10}, dest{ W1_west, 10}, dest{ C1_east, 80});
    W1_east->set_destinations( dest{ C1_east, 80}, dest{N1_north, 10}, dest{S1_south, 10});
    C1_west->set_destinations( dest{ W1_west, 40}, dest{S1_south, 30}, dest{N1_north, 30});
    C1_east->set_destinations( dest{ E1_east, 40}, dest{N2_north, 30}, dest{S2_south, 30});

    // Attach lanes to semaphores
    S1->setLanes(N1_south, C1_west, S1_north, W1_east);
    S2->setLanes(N2_south, E1_west, S2_north, C1_east);

    // Create dummy events
    for (int i = 0; i < sem_.size(); ++i) {
        handler_.schedule({semaphore_time_, kChangeSemaphore, sem_.at(i)});
        handler_.schedule({semaphore_time_, kChangeLane, sem_.at(i)});
    }

    for (int i = 0; i < source_.size(); ++i) {
        SourceLane* source = source_.at(i);
        handler_.schedule({source->spawn_interval(), kSpawnVehicle, source});
    }
}

void System::run() {
    while (handler_.next_event().time() <= simulation_time_) {
        handler_.processNextEvent();
    }
    report();
}

void System::report() {
	int entered = 0;
	int missed = 0;
	int exited = 0;
	int total = 0;
	for (int i = 0; i < source_.size(); ++i) {
		entered += source_.at(i)->entered();
		missed += source_.at(i)->missed();
		total += source_.at(i)->size();
	}
	for (int i = 0; i < center_.size(); ++i) {
		total += center_.at(i)->size();
	}
	for (int i = 0; i < consumer_.size(); ++i) {
		exited += consumer_.at(i)->exited();
		total += consumer_.at(i)->size();
	}

	ost << "Tempo da simulação: " << handler_.current_time() << "s\n"
			<< "Intervalo de troca do semáforo: " << semaphore_time_ << "s\n"
			<< "Nº de carros que entraram no sistema: " << entered << '\n'
			<< "Nº de carros que sairam do sistema: " << exited << '\n'
			<< "Nº de carros que estão no sistema: " << total << '\n'
			<< "Nº de carros que não conseguiram entrar no sistema: " << missed << '\n';
 }
