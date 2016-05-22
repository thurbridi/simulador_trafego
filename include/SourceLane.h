#ifndef SOURCELANE_HPP
#define SOURCELANE_HPP

#include "Lane.h"


class SourceLane : public Lane {
 public:
    SourceLane(int space, int travel_time, int base_frequency, int variation);

    int generateSpawnTime() const;

    int min_time() const;

    int max_time() const;
    
    int base_frequency() const;

    int variation() const;

 private:
    int min_time_;
    int max_time_;
};

#endif
