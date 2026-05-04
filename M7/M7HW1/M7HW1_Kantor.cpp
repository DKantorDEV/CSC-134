#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void drawSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}

void drawRectangle(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}

void drawTriangle(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < size - i; j++) cout << " ";
        for (int j = 0; j < 2 * i - 1; j++) {
            if (j == 0 || j == 2 * i - 2 || i == size)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}

void drawRightTriangle(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i - 1 || i == size)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}

void drawDiamond(int size) {
    int n = (size % 2 == 0) ? size + 1 : size;
    int half = n / 2;
    for (int i = 0; i <= half; i++) {
        for (int j = 0; j < half - i; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    for (int i = half - 1; i >= 0; i--) {
        for (int j = 0; j < half - i; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}

void drawCircle(int radius) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            double dist = sqrt((double)(i * i) + (double)(j * j));
            if (dist >= radius - 0.5 && dist <= radius + 0.5)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}

void drawStar(int size) {
    int n = (size % 2 == 0) ? size + 1 : size;
    int half = n / 2;
    // top half of diamond
    for (int i = 0; i <= half; i++) {
        for (int j = 0; j < half - i; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
    // bottom half
    for (int i = half - 1; i >= 0; i--) {
        for (int j = 0; j < half - i; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
}

void printMenu() {
    cout << "\n===== ASCII Shape Drawer =====\n";
    cout << "1. Square\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle (Isosceles)\n";
    cout << "4. Right Triangle\n";
    cout << "5. Diamond\n";
    cout << "6. Circle\n";
    cout << "7. Filled Star\n";
    cout << "0. Exit\n";
    cout << "==============================\n";
    cout << "Choose a shape: ";
}

int main() {
    int choice;
    do {
        printMenu();
        cin >> choice;

        if (choice == 1) {
            int size;
            cout << "Enter size: ";
            cin >> size;
            cout << "\n";
            drawSquare(size);
        } else if (choice == 2) {
            int w, h;
            cout << "Enter width and height: ";
            cin >> w >> h;
            cout << "\n";
            drawRectangle(w, h);
        } else if (choice == 3) {
            int size;
            cout << "Enter size: ";
            cin >> size;
            cout << "\n";
            drawTriangle(size);
        } else if (choice == 4) {
            int size;
            cout << "Enter size: ";
            cin >> size;
            cout << "\n";
            drawRightTriangle(size);
        } else if (choice == 5) {
            int size;
            cout << "Enter size: ";
            cin >> size;
            cout << "\n";
            drawDiamond(size);
        } else if (choice == 6) {
            int radius;
            cout << "Enter radius: ";
            cin >> radius;
            cout << "\n";
            drawCircle(radius);
        } else if (choice == 7) {
            int size;
            cout << "Enter size: ";
            cin >> size;
            cout << "\n";
            drawStar(size);
        } else if (choice != 0) {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
