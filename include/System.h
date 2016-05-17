#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "structures/ArrayList.hpp"
#include "Event.h"
#include "EventHandler.h"
#include "Lane.h"
#include "Semaphore.h"

class System {
 public:
    void setUp();

    void run();

    void showResults();

 private:
    ArrayList<Lane*> lane_;
    ArrayList<Semaphore*> sem_;
    EventHandler handler_;
};

#endif
