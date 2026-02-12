// CSC-134
// M3LAB2
// Daniel Kantor
// February 12, 2025
// Numberical Grade to Letter Converter


#include <iostream>
using namespace std;



int main() {

    // Variables Declared Here
    int user_number;

    cout << "\n---------------- Numberical Grade Converter ----------------\n" << endl;

    cout << "Please enter the grade you want converted to a letter: ";
    cin >> user_number;

    if (user_number > 100 || user_number < 0) {
        cout << "\nThat is not a valid range. Exiting...\n" << endl;
    }
    else {
        if (user_number >= 90) {
            cout << "Your grade is an A." << endl;
        }
        else if (user_number >= 80) {
            cout << "Your grade is a B." << endl;
        }
        else if (user_number >= 70) {
            cout << "Your grade is a C." << endl;
        }
        else if (user_number >= 60) {
            cout << "Your grade is a D." << endl;
        }
        else {
            cout << "Your grade is an F." << endl;
        }
    }

    return 0;

}