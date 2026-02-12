// CSC-134
// M3LAB1
// Daniel Kantor
// February 12, 2025
// Interactive Adventure Game with User


#include <iostream>
#include <string>
using namespace std;

// ------------------------------------------------------------------------------------------------------------------------------------------------------------

void continue_game_func();
void start_adventure();
void middle_adventure();
void last_adventure();

// ------------------------------------------------------------------------------------------------------------------------------------------------------------

// Global Variables Declared Here
    bool continue_game = true;
    string continue_choice;

// ------------------------------------------------------------------------------------------------------------------------------------------------------------

int main() {
    while (continue_game == true) {
        cout << "Welcome to Kantor's Adventure Game! Would you like to begin?" << endl;
        cout << "Type 'yes' or 'no': ";
        cin >> continue_choice;

        continue_game_func();
    }
    return 0;
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------

void continue_game_func() {
    if (continue_choice == "Yes" || continue_choice == "yes" || continue_choice == "y") {
        cout << "\nEnjoy the adventure that lies ahead!" << endl;
        start_adventure();
    }
    else if (continue_choice == "No" || continue_choice == "no" || continue_choice == "n") {
        cout << "\nThanks for playing! Goodbye, Adventurer!" << endl;
        continue_game = false;
    }
    else {
        cout << "\nNot a valid response...exiting now" << endl;
        continue_game = false;
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------

void start_adventure() {
    cout << "\n--- You Teleport to a Mysterious Realm ---" << endl;
    cout << "You sense danger in your area...you hear a loud growl close by!" << endl;
    
    string fight_or_flight;
    bool valid_input = false;

    while (!valid_input) {
        cout << "A mysterious creature lunges at you! What's your next move? (fight) or (run) ";
        cin >> fight_or_flight;

        if (fight_or_flight == "Fight" || fight_or_flight == "fight") {
            cout << "\nYou were mauled to death...pathetic." << endl;
            continue_game = false;
            valid_input = true;
        }
        else if (fight_or_flight == "Run" || fight_or_flight == "run") {
            cout << "\nYou managed to escape the creature and reach a nearby town." << endl;
            valid_input = true;
            middle_adventure();
            return; // Exit this function entirely after the next one finishes
        }
        else {
            cout << "\nPlease choose a valid response, Adventurer." << endl;
        }
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------

void middle_adventure() {
    cout << "\nYour belly rumbles in hunger. You need to satiate your hunger." << endl;

    string user_choice;
    bool valid_input = false;

    while (!valid_input) {
        cout << "You see a tavern, do you want to enter? (yes) or (no) ";
        cin >> user_choice;

        if (user_choice == "Yes" || user_choice == "yes" || user_choice == "y") {
            cout << "\nYou enter the tavern and approach the bartender. You ask for a burger and fries." << endl;
            valid_input = true;
            last_adventure();
            return; // Exit this function
        }
        else if (user_choice == "No" || user_choice == "no" || user_choice == "n") {
            cout << "\nYou decided not to enter the tavern and the mysterious creature caught up to you." << endl;
            cout << "You turn around, it pounces at you and mauls you to death!" << endl;
            cout << "\nGAME OVER!\n" << endl;
            continue_game = false;
            valid_input = true;
        }
        else {
            cout << "\nPlease choose a valid response." << endl;
        }
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------

void last_adventure() {
    cout << "He stares at you menacingly. He shoots you in the face for disrespecting him." << endl;
    cout << "\nGAME OVER!\n" << endl;
    continue_game = false;
}