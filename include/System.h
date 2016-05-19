#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "structures/ArrayList.hpp"
#include "Event.h"
#include "EventHandler.h"
#include "Lane.h"
#include "SourceLane.h"
#include "ConsumerLane.h"
#include "Semaphore.h"

class System {
 public:
    System(int simulation_time, int semaphore_time);

    ~System();

    void setUp();

    void run();

    void showResults();

 private:
    int simulation_time_, semaphore_time_;
    ArrayList<Lane*> lane_;
    ArrayList<Semaphore*> sem_;
    EventHandler handler_;
};

#endif
