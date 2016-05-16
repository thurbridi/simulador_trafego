#ifndef EVENT_H_
#define EVENT_H_

#include "TrafficEnum.h"


class Event {
 public:
    Event(int time, EventType type, void* source);

    int time() const;

    EventType type() const;

    void* elementA() const;

    bool operator<(const Event& e) const;

 private:
    int time_;
    EventType type_;
    void* source_;
};

#endif
