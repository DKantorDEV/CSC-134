// M6LAB1 - Slime Roulette
// Daniel Kantor
// April 20, 2026

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Function prototypes
void loadMagazine(vector<char>& mag, int slime, int water);
void displayMagazine(const vector<char>& mag);
char fireShot(vector<char>& mag);
void shuffleMagazine(vector<char>& mag);
void identifyRound(char shell);

// --------------------------------------------- Main Function ----------------------------------------------------------------

int main() {
    vector<char> magazine;

    int slime = 3;
    int water = 2;
    loadMagazine(magazine, slime, water);
    displayMagazine(magazine);

    if (!magazine.empty()) {
        shuffleMagazine(magazine);
        char s = fireShot(magazine);
        cout << "You fired: " << s << endl;
        identifyRound(s);
    }

    displayMagazine(magazine);
}

// --------------------------------------------- Load Magazine ----------------------------------------------------------------

void loadMagazine(vector<char>& mag, int slime, int water) {
    mag.clear();

    for (int i = 0; i < slime; i++) mag.push_back('S');
    for (int i = 0; i < water; i++) mag.push_back('W');

    random_device rd;
    mt19937 gen(rd());
    shuffle(mag.begin(), mag.end(), gen);
}

// --------------------------------------------- Display Magazine ----------------------------------------------------------------

void displayMagazine(const vector<char>& mag) {
    int s = 0, w = 0;

    for (char shell : mag) {
        if (shell == 'S') s++;
        else              w++;
    }

    cout << "Magazine: " << mag.size()
         << " remaining ("
         << s << " slime, "
         << w << " water)\n";
}

// --------------------------------------------- Fire Shot -----------------------------------------------------------------------

char fireShot(vector<char>& mag) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, mag.size() - 1);
    int idx = dist(gen);
    char shell = mag[idx];
    mag.erase(mag.begin() + idx);
    return shell;
}

// --------------------------------------------- Shuffle Magazine ------------------------------------------------------------------

void shuffleMagazine(vector<char>& mag) {
    random_device rd;
    mt19937 gen(rd());
    shuffle(mag.begin(), mag.end(), gen);
}

// ------------------------------------------------ identifyRound -----------------------------------------------------------------------

void identifyRound(char shell) {
    if (shell == 'S')
        cout << "That was SLIME!\n";
    else
        cout << "That was WATER.\n";
}