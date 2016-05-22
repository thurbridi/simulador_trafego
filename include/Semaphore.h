#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include "Lane.h"
#include "structures/ArrayList.hpp"

enum SemaphoreState {
    kNorth,
    kEast,
    kSouth,
    kWest
};

class Semaphore {
 public:
    Semaphore(int interval);

    void setLanes(Lane *north, Lane *east, Lane *south, Lane *west);

    void changeState();

    Lane* freeLane() const;

    int interval() const;

 private:
    int interval_;
    ArrayList<Lane*> lanes_;
    SemaphoreState state_;
};

#endif

/*
  S1:
    O1leste ---> C1leste (80%)
            \--> N1norte (10%)
             \-> S1sul   (10%)

    N1sul ---> C1leste (80%)
          \--> O1oeste (10%)
           \-> S1sul   (10%)

    S1norte ---> C1leste (80%)
            \--> N1norte (10%)
             \-> O1oeste (10%)

    C1oeste ---> O1oeste (40%)
            \--> N1norte (30%)
             \-> S1sul   (30%)

  S2:
    C1leste ---> L1leste (40%)
            \--> N2norte (30%)
             \-> S2sul   (30%)

    N2sul ---> L1leste (40%)
          \--> C1oeste (30%)
           \-> S2sul   (30%)

    S2norte ---> L1leste (40%)
            \--> N1norte (30%)
             \-> O1oeste (30%)

    L1oeste ---> N2norte (40%)
            \--> C1leste (30%)
             \-> S2sul   (30%)
*/
