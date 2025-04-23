#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int size = 2 * n - 1;

    for (int i = 0; i < size; ++i) {
        if (i == 0 || i == size - 1) {
            // First and last line: alternating stars and spaces
            for (int j = 0; j < size; ++j) {
                if (j % 2 == 0)
                    cout << "*";
                else
                    cout << " ";
            }
        } else {
            // Determine how many leading spaces for current row
            int spaces = (i < n) ? i : size - i - 1;
            // Print leading spaces
            for (int j = 0; j < spaces; ++j) cout << " ";
            // Print first star
            cout << "*";
            // Print hollow spaces or second star
            int innerSpaces = size - 2 * spaces - 2;
            if (innerSpaces >= 0) {
                for (int j = 0; j < innerSpaces; ++j) cout << " ";
                if (innerSpaces >= 0)
                    cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}

