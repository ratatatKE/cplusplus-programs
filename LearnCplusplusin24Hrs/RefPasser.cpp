//
// Created by Moses Ndeda on 07.08.2025.
//
//Rewrites the ConstPasser.cpp program to use references rather than contant pointers.
/*
 * Because you know the parameters will never be NULL, it easier to work with the function
 * if references are passed in rather than pointers.
 */

#include <iostream>
#include <bits/ostream.tcc>

class SimpleCat {
public:
    SimpleCat();

    SimpleCat(SimpleCat &);

    ~SimpleCat();

    int GetAge() const { return itsAge; }
    void SetAge(int age) { itsAge = age; }

private:
    int itsAge;
};

SimpleCat::SimpleCat() {
    std::cout<<"Simple Cat constructor"<<std::endl;
    itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat &) {
    std::cout<<"Simple Cat copy constructor"<<std::endl;
}


SimpleCat::~SimpleCat() {
    std::cout<<"Simple Cat destructor"<<std::endl;
}

const SimpleCat & FunctionTwo(const SimpleCat & theCat); // function prototype

int main() {
    std::cout<<"Making a cat..."<<std::endl;
    SimpleCat Frisky;

    std::cout<<"Frisky is "<<Frisky.GetAge()<<" years old"<<std::endl;

    int age = 5;
    Frisky.SetAge(age);
    std::cout<<"Frisky is "<<Frisky.GetAge()<<" years old"<<std::endl;

    std::cout<<"Calling FunctionTwo..."<<std::endl;
    FunctionTwo(Frisky);
    std::cout<<"Frisky is "<<Frisky.GetAge()<<" years old"<<std::endl;
    return 0;
}

//FunctionTwo passes a ref to a const object
const SimpleCat & FunctionTwo(const SimpleCat & theCat) {
    std::cout<<"Function Two. Returning..."<<std::endl;
    std::cout<<"Frisky is now "<<theCat.GetAge()<<" years old"<<std::endl;
    // theCat.SetAge(80); //should fail to compile.
    return theCat;
}

