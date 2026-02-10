// CSC 134
// M3T2
// Daniel Kantor
// February 10, 2025
// Random Dice rolls to see what we land on


#include <iostream>
// pseudo-random numbers
#include <cmath>    
// making it truly random
#include <ctime>
using namespace std;


int main() {
    cout << "Let's roll some dice!" << endl;
    int seed = time(0);
    srand(seed);

    const int MAX = 6; // numbers from 1-6
    int roll1, roll2, total;
    roll1  = (rand() % MAX) + 1; // Divide by MAX, and just keep the remainder
    cout << "Your roll was: " << roll1 << endl;

    roll2  = (rand() % MAX) + 1; // Divide by MAX, and just keep the remainder
    cout << "Your roll was: " << roll2 << endl;

    total = roll1 + roll2;
    cout << "Your total roll is: " << total << endl;

    // 7 and 11 - Automatic Win
    // 2 and 12 - Automatic Lose

    if (total == 7) {
        cout << "You got 7! You Won!" << endl;
    }
    else if (total == 11) {
        cout << "You got 11! You Won!" << endl;
    }
    else if (total == 2) {
        cout << "Snake eyes! Too bad, you lose." << endl;
    }
    else if (total == 3) {
        cout << "Sorry, three is unlucky, you lose." << endl;
    }
    else if (total == 12) {
        cout << "Boxcars! Sorry, you lost." << endl;
    }
    else {
        // anything else
        cout << "Your point is " << total << " but we'll do that part later" << endl;
    }

    return 0;
}