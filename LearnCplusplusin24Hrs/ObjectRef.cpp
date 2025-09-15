//
// Created by Moses Ndeda on 07.08.2025.
//
#include <iostream>

class SimpleCat {
public:
    SimpleCat();            //constrctor
    SimpleCat(SimpleCat&);  //copy constructor
    ~SimpleCat();           //destructor
};

SimpleCat::SimpleCat() {
    std::cout<<"Simple Cat constructor"<<std::endl;
}

SimpleCat::SimpleCat(SimpleCat&) {
    std::cout<<"Simple Cat copy constructor"<<std::endl;
}

SimpleCat::~SimpleCat() {
    std::cout<<"Simple Cat destructor"<<std::endl;
}

SimpleCat FunctionOne(SimpleCat theCat); //function prototypes that return SimpleCat
SimpleCat *FunctionTwo(SimpleCat *theCat); //function prototypes that return SimpleCat

int main() {
    std::cout<<"Making a cat..."<<std::endl;
    SimpleCat Frisky;
    std::cout<<"Calling FunctionOne..."<<std::endl;
    FunctionOne(Frisky);
    std::cout<<"Calling FunctionTwo..."<<std::endl;
    FunctionTwo(&Frisky);
    return 0;
}

//FuntionOne Passes by value

SimpleCat FunctionOne(SimpleCat theCat) {
    std::cout<<"Function One. Returning...."<<std::endl;
    return theCat;
}

//FunctionTwo, passes by reference
SimpleCat *FunctionTwo(SimpleCat *theCat) {
    std::cout<<"Function Two. Returning...."<<std::endl;
    return theCat; //return the memory address to SimpleCat
}







