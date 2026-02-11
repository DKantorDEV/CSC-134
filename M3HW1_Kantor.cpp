// CSC-134
// M3HW1 - Gold
// Daniel Kantor
// February 11, 2026

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main() {

    cout << '\n';

    // -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 1 Code Below:

    string userInput;

    cout << "Question 1:" << endl;

    cout << "Hello There! I am KantorGPT. It's nice to meet you! Do you want to tell me your name? Type 'yes' or 'no'." << endl;
    cin >> userInput;

    if (userInput == "yes") {
        cout << "Awesome! What is it?" << endl;
        string yesResponse;
        cin >> yesResponse;
        cout << "It's nice to meet you " << yesResponse << "!" << endl;
    }
    else if (userInput == "no") {
        cout << "Alright. Maybe another time then!" << endl;
    }
    else {
        cout << "Seems like you mistyped, oh well!" << endl;
    }

    cout << '\n';

    // -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 2 Code Below:
    cout << "Question 2:" << endl;



    cout << '\n';


    // -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 3 Code Below:
    cout << "Question 3:" << endl;

    

    cout << endl; 

    // -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Question 4 Code Below:
    cout << "Question 4:" << endl;


    
    cout << '\n';

    return 0;
}