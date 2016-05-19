#include "../include/SourceLane.h"


SourceLane::SourceLane(int space,
                       int travel_time,
                       int base_frequency,
                       int variation)
    : Lane::Lane{space, travel_time},
      base_frequency_{base_frequency},
      variation_{variation}
{}

int SourceLane::base_frequency() const {
    return base_frequency_;
}

int SourceLane::variation() const {
    return variation_;
}
