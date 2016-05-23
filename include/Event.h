#ifndef EVENT_H_
#define EVENT_H_

enum EventType {
    kChangeSemaphore,
    kChangeLane,
    kArrival,
    kSpawnVehicle
};

class Event {
 public:
    Event(int time, EventType type, void* source);

    int time() const;

    EventType type() const;

    void* source() const;

    bool operator<(const Event& e) const;

    bool operator<=(const Event& e) const;

 private:
    int time_;
    EventType type_;
    void* source_;
};

#endif
