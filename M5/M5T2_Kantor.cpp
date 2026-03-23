// CSC-134
// M5T2 - Writing Functions
// Daniel Kantor
// March 23, 2026

#include "m5t2.h"
#include <iostream>
using namespace std;

int main() {

    // Prints out a table of Squares
    cout << "Num\tSquare" << endl;
    int start = 1;
    int finish = 10;
    
    for (int i = start; i <= finish; i++) {
        int sq = square(i);
        print_table_line(i, sq);
    }

    return 0;

}