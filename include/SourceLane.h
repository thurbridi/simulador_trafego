#ifndef SOURCELANE_HPP
#define SOURCELANE_HPP

#include "Lane.h"


class SourceLane : public Lane {
 public:
     SourceLane(int space, int travel_time, int base_frequency, int variation);

     int base_frequency() const;

     int variation() const;

 private:
    int base_frequency_;
    int variation_;
};

#endif
