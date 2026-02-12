// CSC-134
// M3T2
// Daniel Kantor
// February 11, 2025
// Craps Game with C++


#include <iostream>
#include <ctime>
using namespace std;

// -------------------------------------------------- Declared our Variables/Rules---------------------------------------------------------------------

int main() {

    // Declaring methods/variables for the game
    cout << "Let's Play Craps" << endl;
    int seed = time(0);
    srand(seed);
    const int MAX = 6; // numbers from 1-6
    int roll1, roll2, total;

// ---------------------------------------------------- First Roll of the Game ------------------------------------------------------------------------

    // Initial Roll
    roll1  = (rand() % MAX) + 1;
    roll2  = (rand() % MAX) + 1;
    total = roll1 + roll2;
    cout << "You rolled: " << roll1 << " and " << roll2 << " for a total of " << total << endl;

// ---------------------------------------------------- Logic to the Win/Lose -------------------------------------------------------------------------

    // Part 1: Initial Roll Logic
    if (total == 7 || total == 11){
        cout << "You got " << total << "! You won!" << endl;
    }
    else if (total == 2 || total == 3 || total == 12) {
        cout << "You got " << total << "! You Lose!" << endl;
    }
    else {
        // Part 2: Win System
        int target = total; 
        bool gameOver = false; // Bool to continue game or not
        
        cout << "Your target is now " << target << ". Roll Again!" << endl;

        while (!gameOver) {
            // Roll Again for Part 2
            roll1 = (rand() % MAX) + 1;
            roll2 = (rand() % MAX) + 1;
            total = roll1 + roll2;

            cout << "Next roll: " << roll1 << " + " << roll2 << " = " << total << endl;

            // Check the new conditions
            if (total == target) {
                cout << "You hit your target! You Win!" << endl;
                gameOver = true; // Player wins and game ends
            } 
            else if (total == 7) {
                cout << "Seven out! You Lose!" << endl;
                gameOver = true; // This breaks the loop
            } 
            else {
                cout << "Roll Again!" << endl;
            }
        }
    }

    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------