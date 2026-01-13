// CSC-134
// M1HW1
// Daniel Kantor
// January 13, 2026

#include <iostream>
using namespace std;

int main () {
    // Movie Name
    string movieName = "Interstellar";

    // Movie Release Year
    int yearOfMovie = 2014;

    // Movie Gross Earnings
    double grossEarnings = 773.8;

    // Displaying information about my chosen movie
    cout << "My favorite movie is " << movieName;
    cout << "." << endl;
    cout << "It was released in " << yearOfMovie;
    cout << "." << endl;
    cout << "It had a world-wide earnings of $" << grossEarnings;
    cout << " million." << endl;
    cout << "\n";

    // Displaying a few interesting quotes from the movie
    cout << "Below are a few of my favorite quotes!" << endl;
    cout << "\n";
    cout << "Quote 1: \"We used to look up at the sky and wonder at our place in the stars. Now we just look down, and worry about our place in the dirt.\"" << endl;
    cout << "Quote 2: \"Love is the one thing we're capable of perceiving that transcends time and space.\"" << endl;
    cout << "Quote 3: \"After you kids came along, your mom, she said something to me I never quite understood. She said, \"Now, we're just here to be memories for our kids.\" I think now I understand what she meant. Once you're a parent, you're the ghost of your children's future.\"" << endl;
}