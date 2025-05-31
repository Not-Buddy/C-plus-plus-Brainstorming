#include <iostream>
#include <vector>
#include <algorithm>


void diagonal_sort(std::vector<std::vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    // Sort diagonals starting from the first row
    for (int col = 0; col < n; ++col) {
        std::vector<int> diag;
        int x = 0, y = col;
        while (x < m && y < n)
            diag.push_back(mat[x++][y++]);
        std::sort(diag.begin(), diag.end());
        x = 0, y = col;
        int idx = 0;
        while (x < m && y < n)
            mat[x++][y++] = diag[idx++];
    }
    // Sort diagonals starting from the first column (excluding mat[0][0])
    for (int row = 1; row < m; ++row) {
        std::vector<int> diag;
        int x = row, y = 0;
        while (x < m && y < n)
            diag.push_back(mat[x++][y++]);
        std::sort(diag.begin(), diag.end());
        x = row, y = 0;
        int idx = 0;
        while (x < m && y < n)
            mat[x++][y++] = diag[idx++];
    }
}


int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> mat(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> mat[i][j];
        }
    }

    // Call user logic function
    diagonal_sort(mat);

    // Print the sorted matrix
    for (const auto& row : mat) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
