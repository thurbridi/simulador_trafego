#include "../include/Event.h"


Event::Event(int time, EventType type, void* source)
    : time_{time},
      type_{type},
      source_{source}
{}

int Event::time() const {
    return time_;
}

EventType Event::type() const {
    return type_;
}

void* Event::elementA() const {
    return source_;
}

bool Event::operator<(const Event& e) const {
    return time() < e.time();
}