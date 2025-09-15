//
// Created by Moses Ndeda on 06.08.2025.
//
#include  <iostream>

short factor(int, int *, int *);

int main() {
    int number, squared, cubed;

    short error;

    std::cout << "Enter a number (0-20): ";
    std::cin >> number;

    error = factor(number, &squared, &cubed);

    if (!error) {
        std::cout << "number: " << number << std::endl;
        std::cout << "square: " << squared << std::endl;
        std::cout << "cube: " << cubed << std::endl;
    } else {
        std::cout << "Error encountered!!\n";
    }

    return 0;
}

short factor(int n, int *pSquared, int *pCubed) {
    short value = 0;
    if (n > 20) {
        value = 1;
    } else {
        *pSquared = n * n;
        *pCubed = n * n * n;
        value = 0;
    }
    return value;
}
