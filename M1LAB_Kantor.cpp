// CSC-134
// M1LAB
// Daniel Kantor
// January 13, 2026

#include <iostream>
using namespace std;

int main() {
    // The Owners Name
    string name = "Daniel Kantor";
    // Number of Apples Owned
    int apples = 100;
    // Price Per Apple
    double pricePerApple = 0.25;

    // Print all the information about the orchard
    // cout << "Welcome to " << name;

    cout << "Welcome to " << name;
    cout << "'s Apple Orchard." << endl;
    cout << "We have " << apples;
    cout << " apples in stock." << endl;
    cout << "Apples are currently $";
    cout << pricePerApple << " each." << endl;

    // Calculate the total price of the Apples
    double totalPrice = apples * pricePerApple;
    cout << "To purchase all these apples, it will be $" << totalPrice;
    cout << ".ssss" << endl;
}