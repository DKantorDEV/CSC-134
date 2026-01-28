// CSC-134
// M2T2
// Daniel Kantor
// January 13, 2026

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string name = "Cheese Pizza";
    double priceOfMeal = 5.99;
    int taxInteger = 8;
    double taxDouble = 1.08;
    double totalAmount = priceOfMeal * taxDouble;

    cout << setprecision(2) << fixed << endl;
    cout << "Meal: Cheese Pizza" << endl;
    cout << "Price before Tax: $" << priceOfMeal << endl;
    cout << "Tax: " << taxInteger << "%" << endl;
    cout << "Total with Tax: $" << totalAmount << endl;
}