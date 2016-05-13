class Event {
 private:
  enum EventType {
    SPAWN_CAR,
    REMOVE_CAR,
    SEMAPHORE_ARRIVAL,
    CHANGE_SEMAPHORE_LIGHTS
  };

  int time;

  EventType type;

 public:
  Event(int time, EventType type): time(time), type(type) {}

  ~Event();

  int getTime() {
    return time;
  }

  int getType() {
    return type;
  }
};