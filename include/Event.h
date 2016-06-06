#ifndef EVENT_H
#define EVENT_H


enum EventType {
    kChangeSemaphore,
    kChangeLane,
    kArrival,
    kSpawnVehicle
};

class Event {
 public:
	Event();

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
