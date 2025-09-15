//
// Below shows how to create and delete objects on the heap. When you call delete() on
// a pointer to an object on the heap, the object's destructor is called before memory
// is released. This gives your class a chance to clean up, just as it does for
// other destroyed objects on the stack
//
// Created by Moses Ndeda on 04.08.2025.
//

#include <iostream>

class SimpleCat {
    public:
        SimpleCat();
    ~SimpleCat();

    private:
        int itsAge;
};

SimpleCat::SimpleCat() {
    std::cout << "Constructor called\n";
    itsAge = 1;
}

SimpleCat::~SimpleCat() {
    std::cout << "Destructor called\n";
}

int main() {
    std::cout<<"SimpleCat Frisky....\n";
    SimpleCat Frisky; // I think this creates the object on the stack

    std::cout<<"SimpleCat *pRags = new SimpleCat ......\n";
    SimpleCat *pRags = new SimpleCat; // I think this creats the object on the heap

    std::cout<<"delete pRag s ..... \n";
    delete pRags; // Since it is on the heap we have to deallocate memory manually

    std::cout<<"Exiting, watch Frisky go....\n";
    return 0;
}

