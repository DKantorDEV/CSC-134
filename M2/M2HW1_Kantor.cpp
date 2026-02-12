// CSC-134
// M2HW1 - Gold
// Daniel Kantor
// January 14, 2026

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {


    // -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 1 Code Below:
    cout << "Question 1:" << endl;

    string name;
    double startBalance = 1237.24;
    double deposit;
    double withdrawal;


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

    cout << '\n';


    // -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 2 Code Below:
    cout << "Question 2:" << endl;

    const double COST_PER_CUBIC_FOOT = 0.3;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;

    double length, width, height, volume, cost, charge, profit;

    cout << fixed << setprecision(2);

    // Prompt to ask for dimensions of the crate

    cout << "Please enter the length of the crate in feet." << endl;
    cin >> length;
    cout << "Please enter the width of the crate in feet." << endl;
    cin >> width;
    cout << "Please enter the height of the crate in feet." << endl;
    cin >> height;

    volume = length * width * height;

    // Below is the code to calculate the cost of building the crate

    cost = volume * COST_PER_CUBIC_FOOT;

    // Below is the code to calculate the customers charge

    charge = volume * CHARGE_PER_CUBIC_FOOT;

    // Below is the code to calculate the profit made

    profit = charge - cost;

    // Below is all the code displayed.
    cout << "The volume of the crate is: " << volume << " cubic feet." << endl;
    cout << "Cost to build: $" << cost << "." << endl;
    cout << "Charge to customer: $" << charge << "." << endl;
    cout << "Profit: $" << profit << "." << endl;

    cout << '\n';


    // -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 3 Code Below:
    cout << "Question 3:" << endl;

    int pizza;
    int slices;
    int visitors;
    int slicesPerVisitor = 3;

    cout << "How many pizzas would you like to order?" << endl;
    cin >> pizza;
    cout << "How many slices per pizza?" << endl;
    cin >> slices;
    cout << "How many visitors will there be?" << endl;
    cin >> visitors;

    int totalSlices = pizza * slices;
    int slicesLeftOver = totalSlices - (visitors * slicesPerVisitor);

    if (slicesLeftOver > 0) {
        cout << "You will have " << slicesLeftOver << " slices of pizza left over." << endl;
    }
    else {
        int slicesShort = (visitors * slicesPerVisitor) - totalSlices;
        cout << "You are short " << slicesShort << " slices of pizza." << endl;
    }

    cout << endl; 

    // -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 4 Code Below:
    cout << "Question 4:" << endl;

    string school = " FTCC";
    string team = " Trojans";
    string letsGo = "Let's Go";
    string cheerOne = letsGo + school;
    string cheerTwo = letsGo + team;

    cout << cheerOne << '\n' << cheerOne << '\n' << cheerOne << endl;
    cout << cheerTwo << endl;

    return 0;
}