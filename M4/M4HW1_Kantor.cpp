// CSC-134
// M4HW1 - Gold
// Daniel Kantor
// February 18, 2026


#include <iostream>
#include <iomanip>
using namespace std;

//--------------------------------------------------------------------------------------------------------------

int get_table_size();
void display_table(int size);

//--------------------------------------------------------------------------------------------------------------

int main() {
    char choice;

    do {
        int number = get_table_size();
        display_table(number);

        cout << "Do you want to enter another number? (y/n): ";
        cin >> choice;
        cin.ignore(1000, '\n');

    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;

    return 0;
}

//--------------------------------------------------------------------------------------------------------------

int get_table_size() {
    int num;
    cout << "\nEnter a number from 1 to 12? ";
    
    // Used CoPilot to guide me here as this is more advanced
    while (!(cin >> num) || num < 1 || num > 12) {
        cout << "Invalid. Please enter a number between 1 and 12: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return num;
}

//--------------------------------------------------------------------------------------------------------------

void display_table(int num) {

    cout << '\n' << endl;

    for (int i = 1; i <= 12; ++i) {
        cout << num << " times " << i << " is " << num * i << "." << endl;
    }

    cout << '\n' << endl;

}