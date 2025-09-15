//
// Created by Moses Ndeda on 13.08.2025.
//

/**
 * nested loops:
 *
 * Loops can be nested with one loop sitting in the body of another.
 * The inner loop will be executed in its entirerty for each/every one execution of the outer loop.
 */
#include <iostream>

int main(int argc, char ** argv) {
    int rows, columns;
    std::string character;

    std::cout << "How many rows: ";
    std::cin >> rows;
    std::cout << "How many columns: ";
    std::cin >> columns;
    std::cout << "What character do we use to draw the box? ";
    std::cin >> character;

    // if (argc == 4){
    //     rows = std::stoi(argv[1]);
    //     columns = std::stoi(argv[2]);
    //     character = argv[3];
    // }else {
    //     std::cout<<"Invalid number of arguments!"<<std::endl;
    // }

    std::cout << "\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << character;
        }
        std::cout << "\n";
    }


    //end of main
    return 0;
}
