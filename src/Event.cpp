#include "../include/Event.h"


Event::Event(int time, EventType type, void* element_A, void* element_B = nullptr)
    : time_{time},
      type_{type},
      element_A_{element_A},
      element_B_{element_B} 
{}

int Event::time() const {
    return time_;
}

Event::EventType Event::type() const {
    return type_;
}

void* Event::elementA() const {
    return element_A_;
}

void* Event::elementB() const {
    return element_B_;
}

bool Event::operator<(const Event& e) const {
    return time() < e.time();
}