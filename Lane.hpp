#ifndef LANE_HPP
#define LANE_HPP

#include <encadeadas/FilaEnc.hpp>

class Lane {
 private:
  int speed,
      size,
      available_space,
      travel_time,
      spawn_frequency,
      frequency_variation;

  enum type {
    SOURCE,
    CONSUMER,
    NORMAL
  };

 public:
  Lane();
  ~Lane();

  int getSpeed() {
    return speed;
  }

  int getSize() {
    return size;
  }

  int getAvailableSpace() {
    return available_space;
  }

  int getTravelTime() {
    return travel_time;
  }

  int getSpawnFrequency() {
    return spawn_frequency;
  }

  int getFrequencyVariation() {
    return frequency_variation;
  }


};

#endif
