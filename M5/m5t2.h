// CSC-134
// M5T2 - Writing Functions
// Daniel Kantor
// March 23, 2026

#include <iostream>
using namespace std;

#ifndef M5T2_H_INCLUDED
#define M5T2_H_INCLUDED

int square(int num) {
    int answer = num * num;
    return answer;
}

void print_table_line(int first, int second) {
    // input: two numbers
    // effect: prints a line with both numbers
    cout << first << "\t" << second << endl;
}

#endif