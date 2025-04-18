#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    vector<vector<int>> pascal(n);

    for (int i = 0; i < n; i++) 
    {
        pascal[i].resize(i + 1); // Resize row to correct length
        pascal[i][0] = pascal[i][i] = 1; // First and last element is 1

        // Fill in the rest of the row
        for (int j = 1; j < i; j++)
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }

    // Print Pascal's Triangle
    for (int i = 0; i < n; i++) {
        // Print leading spaces for formatting
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        for (int j = 0; j <= i; j++)
            cout << pascal[i][j] << " ";
        cout << endl;
    }

    return 0;
}

