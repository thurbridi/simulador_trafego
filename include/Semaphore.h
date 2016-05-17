#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include "Lane.h"

enum SemaphoreState {
    kNorth,
    kWest,
    kSouth,
    kEast
};

class Semaphore {
 public:
    Semaphore(int time);

    void setLanes(Lane* north, Lane* west, Lane* south, Lane* east) {
        lane_.insert(kNorth, north);
        lane_.insert(kWest, west);
        lane_.insert(kSouth, south);
        lane_.insert(kEast, east);
    }

    void changeState();

    int time() const;

 private:
    int time_;
    ArrayList<Lane*> lane_{4};
    SemaphoreState state_{kNorth};
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
