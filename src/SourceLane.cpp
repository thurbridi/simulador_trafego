#include "../include/SourceLane.h"


SourceLane::SourceLane(int space,
                       int travel_time,
                       int base_frequency,
                       int variation)
    : Lane::Lane{space, travel_time},
      min_time_{base_frequency - variation},
      max_time_{base_frequency + variation}
{}

int SourceLane::generateSpawnTime() const {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(min_time(), max_time());
    return dist(rd);
}

int SourceLane::min_time() const { return min_time_; }

int SourceLane::max_time() const { return max_time_; }

int SourceLane::base_frequency() const { return (min_time_ + max_time_) / 2; }

int SourceLane::variation() const { return (max_time_ - min_time_) / 2; }
