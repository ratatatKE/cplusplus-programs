//
// Created by Moses Ndeda on 07.08.2025.
//
#include <iostream>

enum ERR_CODE{SUCCESS, ERROR};

ERR_CODE factor(int, int&, int&);

int main() {
    int number, squared, cubed;

    ERR_CODE result;

    std::cout << "Enter a number: (0-20) ";
    std::cin >> number;

    result = factor(number, squared, cubed);

    if (result == SUCCESS) {
        std::cout << "Original number is " << number << "\n";
        std::cout << "Square is " << squared << "\n";
        std::cout << "Cube is " << cubed << "\n";
    }else {
        std::cout << "Error encountered!!\n";
    }
    return 0;
}

ERR_CODE factor(int n, int &rSquared, int &rCubed) {
    if (n>20) {
        return ERROR; // simple error code
    }else {
        rSquared = n*n;
        rCubed=n*n*n;
        return SUCCESS;
    }
}