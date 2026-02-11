// CSC-134
// M3HW1 - Gold
// Daniel Kantor
// February 11, 2026

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>    
#include <ctime>
using namespace std;

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 1 Code Below:

void question1() {

    string user_input;

    cout << '\n';
    cout << "Question 1:" << endl;

    cout << "Hello There! I am KantorGPT. It's nice to meet you! Do you want to tell me your name? Type 'yes' or 'no'." << endl;
    cin >> user_input;

    if (user_input == "yes") {
        cout << "Awesome! What is it?" << endl;
        string yes_response;
        cin >> yes_response;
        cout << "It's nice to meet you " << yes_response << "!" << endl;
    }
    else if (user_input == "no") {
        cout << "Alright. Maybe another time then!" << endl;
    }
    else {
        cout << "Seems like you mistyped, oh well!" << endl;
    }

}

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 2 Code Below:

void question2() {

    cout << '\n';
    cout << "Question 2:" << endl;

    string choice;
    double price_of_meal;
    double tip_multiplier = 1.15;

    cout << "Will you be dining in or is this for take-out? (1) for Dine-In and (2) for Take-Out" << endl;
    cin >> choice;

    cout << "How much will the meal be?" << endl;
    cin >> price_of_meal;

    double total_amount_dining = price_of_meal * tip_multiplier;
    double tip_only = total_amount_dining - price_of_meal;

    if (choice == "1") {
        cout << setprecision(2) << fixed << endl;
        cout << "Price of Meal:    $" << price_of_meal << endl;
        cout << "Tip (15%):        $" << tip_only << endl;
        cout << "Total:            $" << total_amount_dining << endl;
    } 
    else if (choice == "2") {
        cout << "Price of Meal:    $" << price_of_meal << endl;
        cout << "Total:            $" << price_of_meal << endl;
    } 
    else {
        cout << "There was an ERROR." << endl;
    }
}

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 3 Code Below:

void question3() {

    string door_choice1;

    cout << '\n';
    cout << "Question 3:" << endl;

    cout << "--------------------------- Welcome to Kantor's Adventure Game ---------------------------" << endl;
    cout << '\n';
    cout << "Would you like to go through Door (1) or Door (2)?" << endl;
    cin >> door_choice1;

    if (door_choice1 == "1") {
        string door_choice2;
        cout << "Well done. Now for the final door. (left) or (right)" << endl;
        cin >> door_choice2;
        cout << '\n';

        if (door_choice2 == "left") {
            cout << "Congratulations! YOU SURVIVED!" << endl;
        }
        else if (door_choice2 == "right") {
            cout << "You were attacked by lions and DIED!" << endl;
        }
        else {
            cout << "That was not one of the options." << endl;
        }
        
    }
    else if (door_choice1 == "2") {
        cout << "You fell into a blackhole...YOU LOSE!" << endl;
    }
    else {
        cout << "That was not one of the options." << endl;
    }
}

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 4 Code Below:

void question4() {

    cout << '\n';
    cout << "Question 4:" << endl;

    srand(time(0));
    int user_total, value1, value2, total_value;
    const int MAX = 1000;

    // Total of the Two Values
    value1 = (rand() % MAX) + 1;
    value2 = (rand() % MAX) + 1;
    total_value = value1 + value2;
    
    cout << "The two numbers are: " << value1 << " and " << value2 << endl;
    cout << "So what is " << value1 << " + " << value2 << " = " << "?" << endl;
    cin >> user_total;

    if (user_total == total_value) {
        cout << "Correct!" << endl;
    }
    else {
        cout << "Incorrect! The correct answer was " << total_value << endl;
    }
}

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main() {

    question1();
    question2();
    question3();
    question4();

    return 0;
}