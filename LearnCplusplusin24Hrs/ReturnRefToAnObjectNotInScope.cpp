//
// Created by Moses Ndeda on 07.08.2025.
//

/*
 * This example demonstrates the DANGER of returning a reference to an object
 * that is not in scope.
 */

#include<iostream>

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


SimpleCat::SimpleCat(int age, int weight) : itsAge(age), itsWeight(weight) {}

SimpleCat &TheFunction(); // function prototype

int main() {
    SimpleCat &rCat=TheFunction();
    int age= rCat.GetAge();
    std::cout<<"rCat age is: "<<age<<std::endl;
    return 0;
}

//function implementation
SimpleCat &TheFunction() {
    SimpleCat Frisky(5,9);
    return Frisky;
}














