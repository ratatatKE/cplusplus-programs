//
// Created by Moses Ndeda on 20.08.2025.
//

#include <iostream>

class Tricycle {
public:
    Tricycle(int initialSpeed);

    ~Tricycle();

    int getSpeed();

    void setSpeed(int speed);

    void pedal();

    void brake();

private:
    int speed;
};

//Define/Implement constructor for the object
Tricycle::Tricycle(int initialSpeed) {
    setSpeed(initialSpeed);
}

//Destructor
Tricycle::~Tricycle() {
    //do nothing
}

int Tricycle::getSpeed() {
    return speed;
}

void Tricycle::setSpeed(int newSpeed) {
    if (newSpeed >= 0) {
        speed = newSpeed;
    }
}

//pedal the trike
void Tricycle::pedal() {
    setSpeed(speed + 1);
    std::cout << "\n Pedaling, tricycle speed " << getSpeed() << " kph \n";
}

void Tricycle::brake() {
    setSpeed(speed - 1);
    std::cout << "\n Braking, tricycle speed " << getSpeed() << " kph \n";
}


//create a trike and ride it
int main() {
    Tricycle tricycle(5);
    tricycle.pedal();
    tricycle.pedal();
    tricycle.brake();
    tricycle.brake();
    tricycle.brake();
    return 0;
}
