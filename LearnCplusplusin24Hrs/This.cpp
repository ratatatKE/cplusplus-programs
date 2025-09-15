//
// Created by Moses Ndeda on 04.08.2025.
//

/*
 * The job of this pointer is to point to the individual object whose function has been invoked.
 * Usually, you don't need this; you just call functions and set member variables.
 * Occasionally however, you need to acccess the object itself (e.g.. perhaps to return a pointer to the
 * current object). It is at that point that the this pointer becomes so helpful.
 *
 * You don't need to use the this pointer to access hte member variables of an object from within functions
 * of that object.
 * You can howeer explicity call this pointer if you want to.
 */


#include <iostream>

class  Rectangle {
    public:
        Rectangle();
        ~Rectangle();

        void SetLength(int length){ this->itsLength = length; }
        int GetLength() const { return this->itsLength;}
        // The SetLength() and GetLength() accessor functions explicity use the this pointer to access the member variables
        // of the Rectangle object, the SetWidth() and GetWidth() functions do not.
        // There is no difference in functionality, maybe ease of readability
        void SetWidth(int width){ itsWidth = width;}
        int GetWidth() const {return itsWidth;}

    private:
        int itsLength;
        int itsWidth;
};

Rectangle::Rectangle() {
    itsWidth = 5;
    itsLength = 10;
}

Rectangle::~Rectangle(){}

int main() {
    Rectangle theRect;

    std::cout<<"theREct is "<< theRect.GetLength() <<" feet long \n";
    std::cout<<"theRect is "<< theRect.GetWidth() <<" feet wide \n";

    theRect.SetLength(20);
    theRect.SetWidth(10);

    std::cout <<"theRect is " << theRect.GetLength() << " feet long \n";
    std::cout <<"theRect is " << theRect.GetWidth() << " feet wide \n";

    return 0;
}