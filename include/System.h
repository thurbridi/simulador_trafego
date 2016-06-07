#ifndef SYSTEM_H
#define SYSTEM_H


#include <fstream>
#include "structures/ArrayList.hpp"
#include "CenterLane.h"
#include "ConsumerLane.h"
#include "EventHandler.h"
#include "SourceLane.h"


class System {
 public:
    System(int simulation_time, int semaphore_time);

    ~System();

    void setUp();

    void run();

    void report();

 private:
   int simulation_time_;
   int semaphore_time_;

    ArrayList<Semaphore*> sem_;
    ArrayList<SourceLane*> source_;
    ArrayList<CenterLane*> center_;
    ArrayList<ConsumerLane*> consumer_;

    EventHandler handler_;
    std::ofstream ost{"log.txt"};
};

#endif
