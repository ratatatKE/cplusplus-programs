//
// Created by Moses Ndeda on 04.08.2025.
//
/*
 * References cannot be reassigned and are always aliases for their target. What appears to be a
 * reassignment turns out to be the assignment of a new value to the target
 */
#include <iostream>

int main() {
    int intOne;
    int &rSomeRef=intOne;

    intOne=5;

    std::cout<<"intOne: \t"<<intOne<<"\n";
    std::cout<<"rSomeRef: \t"<<rSomeRef<<"\n";
    std::cout<<"&intOne: \t"<<&intOne<<"\n";
    std::cout<<"&rSomeRef: \t"<<&rSomeRef<<"\n";

    int intTwo = 8;
    rSomeRef=intTwo; //not what you think
    std::cout<<"\nintOne:\t"<<intOne<<"\n";
    std::cout<<"intTwo:\t"<<intTwo<<"\n";
    std::cout<<"rSomeRef:\t"<<rSomeRef<<"\n";
    std::cout<<"&intOne:\t"<<&intOne<<"\n";
    std::cout<<"&intTwo:\t"<<&intTwo<<"\n";
    std::cout<<"&rSomeRef:\t"<<&rSomeRef<<"\n";

    return 0;


}