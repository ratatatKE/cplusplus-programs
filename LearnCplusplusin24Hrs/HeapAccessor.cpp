//
// Created by Moses Ndeda on 04.08.2025.
//

/*
 * This program demonstrates accessing member variables and functions of objects created on the heap.
 * To access Cat object on the heap, you must dereference the pointer and call the dot operator on the object
 * pointed to by the pointer. Therefore, to access the GetAge member function, you write the below:
 *
 *              (*pRags).GetAge()
 *
 * Because this is cumbersome, C++ provides a shorthand operator for indirect access i.e. the -> operator or the points to operator
 * whic is created by typing a dash immediately followed by greator than symbol.
 */


#include <iostream>

class  SimpleCat {
    public:
        SimpleCat() {itsAge = 2;}
        ~SimpleCat() {}
        int GetAge() const {return itsAge;}
        void SetAge(int age) {itsAge = age;}

    private:
        int itsAge;

};

int main() {
        SimpleCat *Frisky = new SimpleCat();
        std::cout<<"Frisky is "<<Frisky->GetAge()<<" years old\n"; // A SimpleCat object is instantiated on the heap. The default constructor sets its age to 2

        Frisky->SetAge(5);
        std::cout<<"Frisky is "<< Frisky->GetAge()<<" years old\n";

        delete Frisky;
        return 0;
}