// CSC 134
// M3T1 
// Daniel Kantor
// February 10, 2026
// Ask the user for width and length of the two rectangles, then find the area

#include <iostream>
using namespace std;


int main() {

    // Our Variables
    double length1, width1, length2, width2; 
    double area1, area2;

    // Ask user for the length and width
    cout << "What's the length of the first rectangle? ";
    cin >> length1;
    cout << "What's the width of the first rectangle? ";
    cin >> width1;
    cout << "What's the length of the second rectangle? ";
    cin >> length2;
    cout << "What's the width of the second rectangle? ";
    cin >> width2;

    // Calculated Area
    area1 = length1 * width1;
    area2 = length2 * width2;

    // Print the area
    cout << "The first area is " << area1 << endl;
    cout << "The second area is " << area2 << endl;

    return 0;
}