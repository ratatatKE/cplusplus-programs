//
// Created by Moses Ndeda on 04.08.2025.
//
/*
 * If you ask a reference for its address, it returns the address of its target. That is the nature of references,
 * they  are aliases for the target.
 */

#include <iostream>

int main() {
    int intOne;
    int &rSomeRef=intOne;

    intOne=5;
    std::cout << "intOne: "<<intOne<<"\n";
    std::cout<<"rSomeRef: "<<rSomeRef<<"\n";


    std::cout << "&intOne: "<<&intOne<<"\n";
    std::cout<<"&rSomeRef: "<<&rSomeRef<<"\n";

    return 0;
}