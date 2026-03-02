#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> 

using namespace std;

// --- FUNCTION DECLARATIONS ---
void clearInputError(); // A helper function to keep our code clean
void drawDice(int face);

// The 4 Game Modes
int playDiceGame();
int playMathChallenge();
int playCountdown();
int playCustomSequence();

int main() {
    srand(time(0)); // Seed random number generator
    
    int totalScore = 0;
    int menuChoice = 0;

    cout << "===========================================\n";
    cout << "     THE ULTIMATE TERMINAL NUMBER GAME     \n";
    cout << "===========================================\n";

    // The Main Menu Loop: Keeps running until the user types 5 to quit
    while (menuChoice != 5) {
        cout << "\nCurrent Total Score: " << totalScore << "\n";
        cout << "--- MAIN MENU ---\n";
        cout << "1. Dice Guessing Game (With Hints!)\n";
        cout << "2. Math Challenge (Arithmetic)\n";
        cout << "3. Countdown (Reach the Target)\n";
        cout << "4. Custom Game (Guess the Sequence)\n";
        cout << "5. Quit Game\n";
        cout << "Choose a mode (1-5): ";
        
        cin >> menuChoice;

        // Input validation for the menu
        if (cin.fail()) {
            clearInputError();
            cout << "Invalid input! Please enter a number 1-5.\n";
            continue;
        }

        // Using a switch statement to route the player to the right game!
        switch (menuChoice) {
            case 1:
                totalScore += playDiceGame(); 
                break;
            case 2:
                totalScore += playMathChallenge();
                break;
            case 3:
                totalScore += playCountdown();
                break;
            case 4:
                totalScore += playCustomSequence();
                break;
            case 5:
                cout << "\nThanks for playing! Final Score: " << totalScore << "\n";
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Pick a number between 1 and 5.\n";
        }
    }

    return 0;
}

// --- HELPER FUNCTION ---
// We use this anytime the user types a letter instead of a number
void clearInputError() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// --- GAME MODE 1: DICE GUESSING (From Step 3) ---
int playDiceGame() {
    int diceRoll = (rand() % 6) + 1; 
    int userGuess;
    int attemptsLeft = 3; 

    cout << "\n--- DICE GUESSING ---\n";
    cout << "I rolled a 6-sided die. You have 3 attempts!\n";

    while (attemptsLeft > 0) {
        cout << "Guess (1-6) [" << attemptsLeft << " tries left]: ";
        cin >> userGuess;

        if (cin.fail()) {
            clearInputError();
            cout << "Numbers only, please!\n";
            continue;
        }

        if (userGuess == diceRoll) {
            cout << "Correct! The die was:\n";
            drawDice(diceRoll);
            if (attemptsLeft == 3) return 10;
            else if (attemptsLeft == 2) return 5;
            else return 2;
        } else if (userGuess < diceRoll) {
            cout << "Too low!\n";
        } else {
            cout << "Too high!\n";
        }
        attemptsLeft--; 
    }
    
    cout << "Out of attempts! It was a " << diceRoll << ".\n";
    return 0; 
}

// --- GAME MODE 2: MATH CHALLENGE ---
int playMathChallenge() {
    cout << "\n--- MATH CHALLENGE ---\n";
    // Generate two numbers between 1 and 20
    int num1 = (rand() % 20) + 1;
    int num2 = (rand() % 20) + 1;
    int answer = num1 + num2;
    int userAnswer;

    cout << "What is " << num1 << " + " << num2 << "?\n";
    cout << "Your answer: ";
    cin >> userAnswer;

    if (cin.fail()) {
        clearInputError();
        cout << "Invalid input. You lose this round!\n";
        return 0;
    }

    if (userAnswer == answer) {
        cout << "Brilliant! +15 points.\n";
        return 15;
    } else {
        cout << "Incorrect! The answer was " << answer << ".\n";
        return 0;
    }
}

// --- GAME MODE 3: COUNTDOWN (Reach the Target) ---
int playCountdown() {
    cout << "\n--- COUNTDOWN: FIND THE OPERATION ---\n";
    int num1 = (rand() % 10) + 1;
    int num2 = (rand() % 10) + 1;
    int target;
    char operation; 
    char userOp;

    // Randomly pick an operation: 0 for +, 1 for -, 2 for *
    int opChoice = rand() % 3; 
    
    if (opChoice == 0) {
        target = num1 + num2;
        operation = '+';
    } else if (opChoice == 1) {
        // Make sure we don't have negative targets for simplicity
        if (num1 < num2) swap(num1, num2); 
        target = num1 - num2;
        operation = '-';
    } else {
        target = num1 * num2;
        operation = '*';
    }

    cout << "To reach the target [" << target << "], what operation goes in the blank?\n";
    cout << num1 << " _ " << num2 << " = " << target << "\n";
    cout << "Enter +, -, or *: ";
    cin >> userOp;

    if (userOp == operation) {
        cout << "Exactly! +20 points.\n";
        return 20;
    } else {
        cout << "Nope! The correct operation was '" << operation << "'.\n";
        return 0;
    }
}

// --- GAME MODE 4: CUSTOM MATH SEQUENCE ---
int playCustomSequence() {
    cout << "\n--- CUSTOM GAME: GUESS THE SEQUENCE ---\n";
    
    // Pick a random starting number (1-10) and a random "step" (2-5)
    int startNum = (rand() % 10) + 1;
    int step = (rand() % 4) + 2; 
    int userAnswer;

    // Calculate the sequence
    int secondNum = startNum + step;
    int thirdNum = secondNum + step;
    int missingNum = thirdNum + step;

    cout << "Find the pattern and guess the next number:\n";
    cout << startNum << ", " << secondNum << ", " << thirdNum << ", [?]\n";
    cout << "Your guess: ";
    cin >> userAnswer;

    if (cin.fail()) {
        clearInputError();
        cout << "Invalid input.\n";
        return 0;
    }

    if (userAnswer == missingNum) {
        cout << "You cracked the code! +25 points.\n";
        return 25;
    } else {
        cout << "Not quite. The sequence was adding " << step << " each time.\n";
        cout << "The answer was " << missingNum << ".\n";
        return 0;
    }
}

// --- ASCII ART FUNCTION ---
void drawDice(int face) {
    switch(face) {
        case 1: cout << " -------\n|       |\n|   o   |\n|       |\n -------\n"; break;
        case 2: cout << " -------\n| o     |\n|       |\n|     o |\n -------\n"; break;
        case 3: cout << " -------\n| o     |\n|   o   |\n|     o |\n -------\n"; break;
        case 4: cout << " -------\n| o   o |\n|       |\n| o   o |\n -------\n"; break;
        case 5: cout << " -------\n| o   o |\n|   o   |\n| o   o |\n -------\n"; break;
        case 6: cout << " -------\n| o   o |\n| o   o |\n| o   o |\n -------\n"; break;
        default: cout << "Invalid dice face!\n";
    }
}