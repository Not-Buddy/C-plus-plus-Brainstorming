#include <iostream>
#include <vector>
using namespace std;

int diagonal_sum(int n) {
    // For all-ones matrix
    return (n % 2 == 0) ? 2 * n : 2 * n - 1;
}

int diagonal_sum(vector<vector<int>>& matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += matrix[i][i];
        sum += matrix[i][n - 1 - i];
    }
    if (n % 2 == 1) sum -= matrix[n / 2][n / 2];
    return sum;
}

int main() {
    int n;
    cin >> n;
    // Try to read the next value. If not present, assume all-ones.
    char c = cin.peek();
    if (c == '\n' || c == EOF) {
        cout << diagonal_sum(n) << endl;
    } else {
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];
        cout << diagonal_sum(matrix, n) << endl;
    }
    return 0;
}

