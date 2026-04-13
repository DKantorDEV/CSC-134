// M6T1
// Daniel Kantor
// April 13, 2026


#include <iostream>
using namespace std;

int main() {

    // Variables
    const int SIZE = 5; // Size of Array set to 5
    int cars[SIZE];     // contains 5 (SIZE) integers
    double sum = 0;
    double average;
    cout << "This program will ask you to enter a count of cars seen." << endl;

    // First Loop: Get Data
    for (int i=0; i<SIZE; i++) {
        cout << "Day " << i+1 << ": ";
        cin >> cars[i];
    }

    // Second Loop: Sum and Average
    for (int i=0; i<SIZE; i++) {
        sum += cars[i];
    }

    average = sum / SIZE;
    cout << "\nOver " << SIZE << " days," << endl;
    cout << "Total cars: " << sum << endl;
    cout << "Average: " << average << "\n" << endl;

    // Extra: Bar Chart
    const int SCALE = 1;  // 1 bar = 1 car
    for (int i = 0; i < SIZE; i++) {
        cout << "DAY " << (i+1) << " | ";
        for (int b = 0; b < cars[i]/SCALE; b++)
            cout << "█";
        cout << " " << cars[i] << "\n";
    }
}