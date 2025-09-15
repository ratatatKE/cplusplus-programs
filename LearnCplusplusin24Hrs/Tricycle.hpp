//
// Created by Moses Ndeda on 20.08.2025.
//

#ifndef TRICYCLE_H
#define TRICYCLE_H
#include <iostream>

#endif //TRICYCLE_H

class TryCycle {
public:
    TryCycle(int initialSpeed);

    ~TryCycle();

    int getSpeed() const { return speed; }

    void setSpeed(int speed);

    void pedal() {
        setSpeed(speed + 1);
        std::cout << "\n Pedaling " << getSpeed() << " kph \n";
    }

    void brake() {
        setSpeed(speed - 1);
        std::cout << "\n Braking " << getSpeed() << " kph \n";
    }

private:
    int speed;
};
