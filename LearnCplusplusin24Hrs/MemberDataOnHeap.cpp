//
// Created by Moses Ndeda on 04.08.2025.
//
/*
 * One or more of the data members of a class can be a pointer to an object on the heap.
 * The memory can be allocated in the classes'
 * constructor or in one of its functions and it can be deleted in its destructor as the program below
 * illustrates
 *
 */

#include <iostream>

class SimpleCat {
    public:
        SimpleCat();
        ~SimpleCat();
        int GetAge() const {return *itsAge;}
        void SetAge(int age) { *itsAge = age;}

        int GetWeight() const { return *itsWeight;}
        void SetWeight(int weight){*itsWeight = weight;}

    private:
        int *itsAge;
        int *itsWeight;
};

SimpleCat::SimpleCat() {
    itsAge = new int(2);
    itsWeight = new int(5);
}

SimpleCat::~SimpleCat() {
    delete itsAge;
    delete itsWeight;
}

int main() {
    SimpleCat *Frisky = new SimpleCat;
    std::cout << "Frisky is " << Frisky->GetAge() << " years old \n";

    Frisky->SetAge(5);
    std::cout << "Frisky is " << Frisky->GetAge() << " years old \n";

    delete Frisky;
    return 0;
}