//
// Created by Moses Ndeda on 04.08.2025.
//

/*
 * If you declare a pointer to a const object, the only functions that you can call with that pointer
 * are const functions. The ConstPointer program below illustrates this.
 */

#include <iostream>

class Rectangle {
    public: Rectangle();
    ~Rectangle();

    void SetLength(int length){itsLength = length;}
    int GetLength()const{ return itsLength;}

    void SetWidth(int width){itsWidth=width;}
    int GetWidth()const{return itsWidth;}

    private:
        int itsLength; int itsWidth;
};

Rectangle::Rectangle():
itsWidth(5),
itsLength(10)
{}

Rectangle::~Rectangle(){}

int main() {
    Rectangle *pRect = new Rectangle;
    const Rectangle *pConstRect = new Rectangle;
    Rectangle* const pConstPtr = new Rectangle;

    std::cout << "pRect width " << pRect->GetWidth()<<" feet\n";

    std::cout << "pConstRect width " << pConstRect->GetWidth()<<" feet\n";

    std::cout<<"pConstPtr width "<< pConstPtr->GetWidth() <<" feet\n";

    pRect->SetWidth(10);
    // pConstRect->SetWidth(10); //pConstRect would be used, but it was declared to point to a constant Rectangle.  Therefore, it cannot legally call a non -const member function and is commented out.
    pConstPtr->SetWidth(10);

    std::cout << "pRect width " << pRect->GetWidth() << " feet\n";

    std::cout << "pConstRect width " << pConstRect->GetWidth() << " feet\n";

    std::cout << "pConstPtr width "<< pConstPtr->GetWidth() <<" feet\n";

    return 0;



}