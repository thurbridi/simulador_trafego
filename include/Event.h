#ifndef EVENT_H_
#define EVENT_H_

#include "TrafficEnum.h"


class Event {
 public:
    Event(int time, EventType type, void* element_A, void* element_B = nullptr);

    int time() const;

    EventType type() const;

    void* elementA() const;

    void* elementB() const;

    bool operator<(const Event& e) const;

 private:
    int time_;
    EventType type_;
    void* element_A_;
    void* element_B_;
};

#endif
