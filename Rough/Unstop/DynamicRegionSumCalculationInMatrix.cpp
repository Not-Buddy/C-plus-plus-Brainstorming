#include <iostream>
#include <vector>

void calculate_sum(const std::vector<std::vector<int>>& matrix, int n, int k) {
    std::vector<std::vector<bool>> used(n, std::vector<bool>(n, false));
    int sum_diag = 0, sum_border = 0, sum_central = 0;

    // 1. Main diagonal and adjacent diagonals
    for (int i = 0; i < n; ++i) {
        // Main diagonal
        if (!used[i][i]) {
            sum_diag += matrix[i][i];
            used[i][i] = true;
        }
        // Above main diagonal
        if (i < n - 1 && !used[i][i + 1]) {
            sum_diag += matrix[i][i + 1];
            used[i][i + 1] = true;
        }
        // Below main diagonal
        if (i > 0 && !used[i][i - 1]) {
            sum_diag += matrix[i][i - 1];
            used[i][i - 1] = true;
        }
    }

    // 2. Border elements
    // Top and bottom rows
    for (int j = 0; j < n; ++j) {
        if (!used[0][j]) {
            sum_border += matrix[0][j];
            used[0][j] = true;
        }
        if (!used[n - 1][j]) {
            sum_border += matrix[n - 1][j];
            used[n - 1][j] = true;
        }
    }
    // Left and right columns (excluding corners already counted)
    for (int i = 1; i < n - 1; ++i) {
        if (!used[i][0]) {
            sum_border += matrix[i][0];
            used[i][0] = true;
        }
        if (!used[i][n - 1]) {
            sum_border += matrix[i][n - 1];
            used[i][n - 1] = true;
        }
    }

    // 3. Central sub-matrix
    int start = (n - k) / 2;
    for (int i = start; i < start + k; ++i) {
        for (int j = start; j < start + k; ++j) {
            if (!used[i][j]) {
                sum_central += matrix[i][j];
                used[i][j] = true;
            }
        }
    }

    std::cout << (sum_diag + sum_border + sum_central) << std::endl;
}


int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    calculate_sum(matrix, n, k);
    return 0;
}
