//
// Created by Moses Ndeda on 07.08.2025.
//
#include <iostream>

class SimpleCat {
public:
    SimpleCat();
    SimpleCat(SimpleCat &);
    ~SimpleCat();

    int GetAge() const {return itsAge;}
    void SetAge(int age) {itsAge = age;}

private:
    int itsAge;
};

SimpleCat::SimpleCat() {
    std::cout<<"Simple Cat Constructor"<<std::endl;
    itsAge =1;
}

SimpleCat::SimpleCat(SimpleCat&) {
    std::cout<<"Simple Cat copy constructor"<<std::endl;
}

SimpleCat::~SimpleCat() {
    std::cout<<"Simple Cat destructor"<<std::endl;
}

const SimpleCat *const FunctionTwo(const SimpleCat *const theCat); //function prototype

int main() {
    std::cout<<"Making a cat..."<<std::endl;
    SimpleCat Frisky;
    std::cout<<"Frisky is ";
    std::cout<<Frisky.GetAge()<<" years old"<<std::endl;

    int age =5;
    Frisky.SetAge(age);

    std::cout<<"Frisky is "<<Frisky.GetAge()<<" years old"<<std::endl;
    std::cout<<"Calling FunctionTwo"<<std::endl;

    FunctionTwo(&Frisky);
    std::cout<<"Frisky is "<<Frisky.GetAge()<<" years old"<<std::endl;
    return 0;
}

//FunctionTwo, passes a const pointer
const SimpleCat *const FunctionTwo(const SimpleCat *const theCat) {
    std::cout<<"FunctionTwo. Returning......."<<std::endl;
    std::cout<<"Frisky is now "<<theCat->GetAge()<<" years old"<<std::endl;
    //theCat->SetAge(8); //should fail compilation
    return theCat;
}















