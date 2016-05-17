#ifndef VEHICLE_H_
#define VEHICLE_H_

enum Direction {
    kFront,
    kLeft,
    kRight,
    kExit
};

class Vehicle {
public:
    Vehicle(Direction destination);

    bool arrived() const;
    void set_arrived();

    int getSize() const;
    Direction direction() const;

private:
    int size_;
    Direction direction_;
    bool arrived_;
};

#endif