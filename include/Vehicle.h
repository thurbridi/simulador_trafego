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
    Vehicle(Direction direction);
    Vehicle(int size, Direction direction);

    bool arrived() const;
    void set_arrived();

    int size() const;
    Direction direction() const;

private:
    int size_;
    Direction direction_;
};

#endif