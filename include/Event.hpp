class Event {
 public:
    enum EventType {
        SPAWN_VEHICLE,
        CHANGE_LANE,
        ARRIVAL,
        CHANGE_SEMAPHORE
    };
    
    Event(int time, EventType type, void* elementA, void* elementB = nullptr)
        : time_{time},
          type_{type},
          elementA_{elementA},
          elementB_{elementB} 
    {}

    int time() const { return time_; }

    EventType type() const { return type_; }

    void* elementA() const { return elementA_; }

    void* elementB() const { return elementB_; }

    bool operator<(const Event& e) { return time() < e.time(); }

 private:
    int time_;
    EventType type_;
    void* elementA_;
    void* elementB_;
};