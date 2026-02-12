// CSC-134
// M2BONUS
// Daniel Kantor
// January 14, 2026

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    cout << fixed << setprecision(2);

    // Question 1 Code Below: ------------------------------------------------------------------------------------------------------------------------------------------

    cout << "Question 1:" << endl;

    int height = 8;
    int width = 10;
    int rectangleArea = height * width;

    cout << "The height is 8 and the width is 10." << endl;
    cout << "The area of the rectangle is " << rectangleArea << "." << endl;

    cout << endl;

    // Question 2 Code Below: ------------------------------------------------------------------------------------------------------------------------------------------

    cout << "Question 2:" << endl;

    double productPrice = 99.99;
    double taxDouble = 1.08;
    int taxInteger = 8;
    double finalCost = productPrice * taxDouble;

    cout << "The products price is $" << productPrice << "." << endl;
    cout << "The sales tax is " << taxInteger << "%." << endl;
    cout << "Final cost for the product is $" << finalCost << "." << endl;

    cout << endl;

    // Question 3 Code Below: ------------------------------------------------------------------------------------------------------------------------------------------

    cout << "Question 3:" << endl;

    double radius = 6;
    double pi = 3.141592653;
    double pizzaArea = pi * (radius) * (radius);

    cout << "The area of the pizza is " << pizzaArea << " inches squared." << endl;

    cout << endl;

    // Question 4 Code Below: ------------------------------------------------------------------------------------------------------------------------------------------

    cout << "Question 4:" << endl;

    double sliceArea = pizzaArea / 8;

    cout << "The area of each of the 8 slices of pizza is " << sliceArea << " inches squared." << endl;

    cout << endl;

}