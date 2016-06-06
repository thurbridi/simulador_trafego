#include "../include/Event.h"


Event::Event()
	: time_{0},
	  type_{(EventType) 0},
	  source_{nullptr}
{}

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

void* Event::source() const {
    return source_;
}

bool Event::operator<=(const Event& e) const {
    return time() <= e.time();
}

bool Event::operator<(const Event& e) const {
    return time() < e.time();
}
