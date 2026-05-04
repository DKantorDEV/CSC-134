// CSC-134
// Daniel Kantor
// May 4, 2026
// GOLD

#include <iostream>
#include "Rectangle.h"
using namespace std;

// Function prototypes
string setName();
void setName(string& name);

int main() {
    string name = "Bob";
    string * pName = &name;
    cout << "name   = " << name << endl;
    cout << "pName  = " << pName << endl;
    cout << "*pName = " << *pName << endl;

    Rectangle r1;
    double w, l;
    cout << "Enter width and length, separated by a space: ";
    cin >> w >> l;
    r1.setWidth(w);
    r1.setLength(l);
    cout << "Area is: " << r1.getArea() << endl;
    r1.drawRectangle();


}

string setName() {
    string name;
    cout << "Enter name: ";
    cin >> name;
    return name;
}

void setName(string& name) {
    cout << "Enter name: ";
    cin >> name;
}