//
// Created by Moses Ndeda on 07.08.2025.
//
/*
 * Trys to put TheFunction() on the heap
 */

#include <iostream>

class SimpleCat {
public:
    SimpleCat(int age, int weight);

    ~SimpleCat();

    int GetAge() { return itsAge; }
    int GetWeight() { return itsWeight; }

private:
    int itsAge;
    int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight): itsAge(age), itsWeight(weight) {}

SimpleCat & TheFunction();

int main() {
    SimpleCat &rCat = TheFunction();
    int age = rCat.GetAge();

    std::cout<<"rCat is "<<age<<" years old"<<std::endl;
    std::cout<<"&rCat: "<<&rCat<<std::endl;

    //So how do you get rid of that memory?
    // SimpleCat *pCat = &rCat;
    // delete pCat;
    // //Oops, so now what does rCat refer to? rCat becomes NULL thereby making the program invalid, a ticking time bomb
    return 0;
}

SimpleCat &TheFunction() {
    SimpleCat *pFrisky = new SimpleCat(5,9);
    std::cout<<"pFrisky: "<<pFrisky<<std::endl;
    return *pFrisky;
}