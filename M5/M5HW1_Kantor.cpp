// CSC 134
// M5HW1 - Gold
// Daniel Kantor
// April 13, 2026

#include <iostream>
#include <iomanip>
#include <string>

// -------------------------------------------------------------------------------------------------------

// Question 1

void questionOne() {

    std::string month1, month2, month3;
    double rain1, rain2, rain3;
    double averageRain, totalRain;

    std::cout << "Enter Month: " << std::endl;
    std::cin >> month1;
    std::cout << "Enter rainfall for " << month1 << ": " << std::endl;
    std::cin >> rain1;

    std::cout << "Enter Month: " << std::endl;
    std::cin >> month2;
    std::cout << "Enter rainfall for " << month2 << std::endl;
    std::cin >> rain2;

    std::cout << "Enter Month: " << std::endl;
    std::cin >> month3;
    std::cout << "Enter rainfall for " << month3 << ": " << std::endl;
    std::cin >> rain3;

    totalRain = rain1 + rain2 + rain3;
    averageRain = totalRain / 3;

    std::cout << std::fixed << std::setprecision(2) << "The average rainfall for " << month1 << ", " << month2 << " and " << month3 << " is " << averageRain << "." << std::endl;

};

// -------------------------------------------------------------------------------------------------------

// Question 2

void questionTwo() {

    double width, length, height, volume;

    std::cout << "Enter the width: " << std::endl;
    std::cin >> width;

    std::cout << "Enter the length: " << std::endl;
    std::cin >> length;

    std::cout << "Enter the height: " << std::endl;
    std::cin >> height;

    if (width <= 0 || length <= 0 || height <= 0) {
        std::cout << "Any given side cannot be 0 or less than 0." << std::endl;
    } else {
        volume = width * length * height;
        std::cout << "The volume is: " << volume << std::endl;
    }

};

// -------------------------------------------------------------------------------------------------------

// Question 3

void questionThree() {

    int userChoice;

    std::cout << "Enter a number (1 - 10): " << std::endl;
    std::cin >> userChoice;

    if (userChoice < 1 || userChoice > 10) {
        std::cout << "Invalid input. Please enter a number between 1 and 10." << std::endl;
        return;
    }

    switch (userChoice) {
        case 1:
            std::cout << "The Roman Numeral version of 1 is I." << std::endl;
            break;
        case 2:
            std::cout << "The Roman Numeral version of 2 is II." << std::endl;
            break;
        case 3:
            std::cout << "The Roman Numeral version of 3 is III." << std::endl;
            break;
        case 4:
            std::cout << "The Roman Numeral version of 4 is IV." << std::endl;
            break;
        case 5:
            std::cout << "The Roman Numeral version of 5 is V." << std::endl;
            break;
        case 6:
            std::cout << "The Roman Numeral version of 6 is VI." << std::endl;
            break;
        case 7:
            std::cout << "The Roman Numeral version of 7 is VII." << std::endl;
            break;
        case 8:
            std::cout << "The Roman Numeral version of 8 is VIII." << std::endl;
            break;
        case 9:
            std::cout << "The Roman Numeral version of 9 is IX." << std::endl;
            break;
        case 10:
            std::cout << "The Roman Numeral version of 10 is X." << std::endl;
            break;
    }

}

// -------------------------------------------------------------------------------------------------------

// Question 4

void questionFour() {

    int userChoice;
    const double pi = 3.14159;

    std::cout << "Geometry Calculator" << std::endl;
    std::cout << "1. Calculate the Area of a Circle" << std::endl;
    std::cout << "2. Calculate the Area of a Rectangle" << std::endl;
    std::cout << "3. Calculate the Area of a Triangle" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << "Enter your choice (1 - 4): " << std::endl;
    std::cin >> userChoice;


    if (userChoice == 1) {

        double radius, area;
        std::cout << "Enter the Radius of the Circle: " << std::endl;
        std::cin >> radius;

        if (radius < 0) {
            std::cout << "The radius cannot be less than zero." << std::endl;
        } else {
            area = pi * radius * radius;
            std::cout << "The Area is " << area << "." << std::endl;
        }

    } else if (userChoice == 2) {

        double area, length, width;

        std::cout << "Enter the Length: " << std::endl;
        std::cin >> length;

        std::cout << "Enter the Width: " << std::endl;
        std::cin >> width;

        if (length < 0 || width < 0) {
            std::cout << "Only enter positive values for length and width." << std::endl;
        } else {
            area = length * width;
            std::cout << "The Area is " << area << "." << std::endl;
        }

    } else if (userChoice == 3) {

        double base, height, area;

        std::cout << "Enter the Base: " << std::endl;
        std::cin >> base;

        std::cout << "Enter the Height: " << std::endl;
        std::cin >> height;

        if (base < 0 || height < 0) {
            std::cout << "Only enter positive values for base and height." << std::endl;
        } else {
            area = base * height * 0.5;
            std::cout << "The Area is " << area << "." << std::endl;
        }

    } else if (userChoice == 4) {

        std::cout << "Quitting Geometry Calculator." << std::endl;

    } else {

        std::cout << "The valid choices are 1 through 4. Run the program again and select one of those." << std::endl;

    }

};

// -------------------------------------------------------------------------------------------------------

// Question 5

void questionFive() {

    double speed;
    int hours;

    std::cout << "What is the speed of the vehicle in mph? ";
    std::cin >> speed;

    std::cout << "How many hours has it traveled? ";
    std::cin >> hours;

    if (speed < 0) {
        std::cout << "Speed cannot be negative." << std::endl;
        return;
    }
    if (hours < 1) {
        std::cout << "Time traveled must be at least 1 hour." << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "Hour    Distance Traveled" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    for (int i = 1; i <= hours; i++) {
        std::cout << std::setw(4) << i << std::setw(8) << (speed * i) << std::endl;
    }

}

// -------------------------------------------------------------------------------------------------------

// Question 6

int main() {

    int userChoice;

    do {
        std::cout << std::endl;
        std::cout << "Main Menu" << std::endl;
        std::cout << "1. Average Rainfall (Question 1)" << std::endl;
        std::cout << "2. Block Volume (Question 2)" << std::endl;
        std::cout << "3. Roman Numerals (Question 3)" << std::endl;
        std::cout << "4. Geometry Calculator (Question 4)" << std::endl;
        std::cout << "5. Distance Traveled (Question 5)" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice (1 - 6): ";
        std::cin >> userChoice;

        std::cout << std::endl;

        if (userChoice == 1) {
            questionOne();
        } else if (userChoice == 2) {
            questionTwo();
        } else if (userChoice == 3) {
            questionThree();
        } else if (userChoice == 4) {
            questionFour();
        } else if (userChoice == 5) {
            questionFive();
        } else if (userChoice == 6) {
            std::cout << "Goodbye!" << std::endl;
        } else {
            std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
        }

    } while (userChoice != 6);

    return 0;
}