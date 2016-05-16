#ifndef VEHICLE_H_
#define VEHICLE_H_

enum Destination {
    kFront,
    kLeft,
    kRight,
    kExit
};

class Vehicle {
public:
    Vehicle(int size, Destination destination);

    bool arrived() const;
    void set_arrived();

    int size() const;
    Destination destination() const;

private:
    int size_;
    Destination destination_;
    bool arrived_;
};

#endif