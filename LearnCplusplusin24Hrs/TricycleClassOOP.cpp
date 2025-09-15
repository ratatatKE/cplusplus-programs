//
// Created by Moses Ndeda on 20.08.2025.
//

#include <iostream>

class Tricycle {
public:
    int getSpeed();
    void setSpeed(int speed);
    void pedal();
    void brake();

private:
    int speed;
};

//Every class member function that YOU DECLARE MUST also be defined.
// A member function definition begins with the name of the clas followed by the scope resolution operator ::

// This syntax tells the compiler that the getSpeed() function you are defining here is the one that you declared in the Tricycle class.
// with the exception of this header line, the getSpeed() function is created like ANY OTHER FUNCTION.

int Tricycle::getSpeed() {
    return speed;
}

//set the trikes speed.
void Tricycle::setSpeed(int newSpeed) {
    if (speed >=0) {
        speed = newSpeed;
    }
}

//Pedal the trike
void Tricycle::pedal() {
    setSpeed(speed + 1);
    std::cout<<"\n Pedaling tricycle speeed "<< speed <<" kph \n";
}

//apply brake
void Tricycle::brake() {
    setSpeed(speed - 1);
    std::cout<<"\n Braking, tricycle speed "<<speed<<" kph\n";
}

//create a trike object and ride it.

int main() {
    Tricycle tricycle;
    tricycle.setSpeed(0);
    tricycle.pedal();
    tricycle.pedal();
    tricycle.brake();
    tricycle.brake();
    tricycle.brake();
    tricycle.brake();
    return 0;
}

































