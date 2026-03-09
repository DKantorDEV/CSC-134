// CSC-134
// M4LAB1
// Daniel Kantor
// March 9, 2026


#include <iostream>

int main() {
    int userWidth;
    int userLength;

    std::cout << "Enter the width:  ";
    std::cin >> userWidth;
    std::cout << "Enter the length: ";
    std::cin >> userLength;

    // Loop for rows
    for (int i = 0; i < userLength; i++) {
        
        // Loop for columns
        for (int j = 0; j < userWidth; j++) {
            std::cout << "* ";
        }

        std::cout << std::endl;
    }

    return 0;
}