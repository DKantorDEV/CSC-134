// CSC-134
// M2LAB1
// Daniel Kantor
// January 13, 2026

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    // Bellow are the variables to be used
    // COST_PER_CUBIC_FOOT
    // CHARGE_PER_CUBIC_FOOT
    // length
    // width
    // height
    // volume
    // cost
    // charge
    // Profit

    const double COST_PER_CUBIC_FOOT = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.5;

    double length, width, height, volume, cost, charge, profit;

    cout << setprecision(2) << fixed << showpoint;

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
    return 0;
}