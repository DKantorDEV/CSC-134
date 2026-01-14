// CSC-134
// M2HW1 - Gold
// Daniel Kantor
// January 14, 2026

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    // Some varaibles will be stored here
    string name;
    double startBalance = 1237.24;
    double deposit;
    double withdrawal;

    // Question 1 Code

    cout << "Welcome to Kantor Banking! What is your name?" << endl;
    getline(cin, name);

    cout << fixed << setprecision(2);

    cout << "Hello " << name << "." << endl;
    cout << "Available Balance: $" << startBalance << endl;
    cout << "Deposit Amount: " << endl;
    cin >> deposit;

    cout << "Withdrawal Amount: " << endl;
    cin >> withdrawal;

    double endBalance = startBalance + deposit - withdrawal;

    cout << "Account Name: " << name << endl;
    cout << "Account Number: 1234567890" << endl;
    cout << "Account Balance: $" << endBalance << endl;

    return 0;
}