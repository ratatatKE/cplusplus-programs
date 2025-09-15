//
// Created by Moses Ndeda on 06.08.2025.
//
#include <iostream>

void swap(int x, int y);

int main() {
    int x=5, y=10;
    std::cout<<"Main before swap x: "<<x<<" y: "<<y<<std::endl;
    swap(x,y);
    std::cout<<"Main after swap x: "<<x<<" y: "<<y<<std::endl;
    return 0;
}

void swap(int x, int y) {
    int temp;

    std::cout<<"Swap before swap, x: "<<x<<" y: "<<y<<std::endl;

    temp=x;
    x=y;
    y=temp;

    std::cout<<"Swap after swap, x: "<<x<<" y: "<<y<<std::endl;

}
