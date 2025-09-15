//
// Created by Moses Ndeda on 20.08.2025.
//
#include "Tricycle.hpp"

//constructor for the object
TryCycle::TryCycle(int initialSpeed) {
    setSpeed(initialSpeed);
}

TryCycle::~TryCycle() {
    //do nothing
}

// set the trike's speed
void TryCycle::setSpeed(int newSpeed) {
    if (newSpeed >= 0) {
        speed = newSpeed;
    }
}

//create a trike and ride it
int main() {
    TryCycle tryCycle(5);
    tryCycle.pedal();
    tryCycle.pedal();
    tryCycle.brake();
    tryCycle.brake();
    tryCycle.brake();
    return 0;
}
