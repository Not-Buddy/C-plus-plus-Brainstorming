#include <iostream>
#include <vector>
using namespace std;
#include <cmath>

// Helper to check if a number is prime
bool is_prime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

// Helper to check if a number is a perfect square
bool is_perfect_square(int x) {
    int r = std::sqrt(x);
    return r * r == x;
}

void transform_matrix(vector<vector<int>>& matrix, int n, int& row_count, int& prime_count) {
    // Step 1: Replace primes with 0, and collect perfect square positions
    vector<pair<int, int>> squares;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (is_prime(matrix[i][j])) {
                matrix[i][j] = 0;
            }
        }
    }
    // Find perfect square positions (ignore 0s)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0 && is_perfect_square(matrix[i][j])) {
                squares.push_back({i, j});
            }
        }
    }
    // Step 2: Mark rows and columns of perfect squares with -1
    vector<bool> row_mark(n, false), col_mark(n, false);
    for (auto& sq : squares) {
        row_mark[sq.first] = true;
        col_mark[sq.second] = true;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (row_mark[i] || col_mark[j])
                matrix[i][j] = -1;

    // Step 3: Count fully -1 rows and count 0s in the final matrix
    row_count = 0;
    prime_count = 0;
    for (int i = 0; i < n; ++i) {
        bool all_minus1 = true;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != -1) all_minus1 = false;
            if (matrix[i][j] == 0) prime_count++;
        }
        if (all_minus1) row_count++;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int row_count = 0;
    int prime_count = 0;
    transform_matrix(matrix, n, row_count, prime_count);

    cout << row_count << " " << prime_count << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
