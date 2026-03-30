// CSC-134
// Daniel Kantor
// M5LAB2
// March 30, 2026

#include <iostream>
using namespace std;

// ----------------------------------------------------------------------------------------------------------

double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double length, double width, double area);

// ----------------------------------------------------------------------------------------------------------

int main() {
	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}

// ----------------------------------------------------------------------------------------------------------

double getLength() {
    double length;
    cout << "\nEnter the length: " << endl;
    cin >> length;
    return length;
}

// ----------------------------------------------------------------------------------------------------------

double getWidth() {
    double width;
    cout << "\nEnter the width: " << endl;
    cin >> width;
    return width;
}

// ----------------------------------------------------------------------------------------------------------

double getArea(double length, double width) {
    double area;
    area = length * width;
    return area;
}

// ----------------------------------------------------------------------------------------------------------

void displayData(double length, double width, double area) {
    cout << "\nLength : " << length << endl;
    cout << "Width  : " << width << endl;
    cout << "Area   : " << area << "\n" << endl;
}
