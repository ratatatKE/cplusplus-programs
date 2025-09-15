//
// Created by Moses Ndeda on 04.08.2025.
//
/*
* You can create a reference by writing the type of the target object, followed by the reference operator &.
* References can use any legal variable name, but in this book all references come prefixed with r and the second letter capitalized.
* So if you have an integer variable named someInt, you can make a reference to that variable by writing the below:
*
* int &rSomeRef = someint;
*
* This is read as "rSomeRef is a reference to an integer that is initialized to refer to someInt.
*/

#include <iostream>

int main() {
    int intOne;
    int &rSomeRef = intOne;

    intOne=5;
    std::cout<<"intone: " <<intOne<<"\n";
    std::cout<<"rSomeRef: "<<rSomeRef <<"\n";

    rSomeRef=7; //notice we have dropped the & //If you declare a reference and don't initialize it you get a compiler error. References must be initialized
    std::cout<<"intone: " <<intOne<<"\n";
    std::cout<<"rSomeRef: "<<rSomeRef <<"\n";

    return 0;
}