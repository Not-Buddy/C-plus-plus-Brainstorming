#include <iostream>
#include <vector>
#include <cmath>

// Helper function to check if a number is prime
bool is_prime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

void zigzag_traversal(int M, int N, std::vector<std::vector<int>>& grid) {
    std::vector<int> result;
    for (int i = 0; i < M; ++i) {
        if (i % 2 == 0) {
            // Traverse left to right
            for (int j = 0; j < N; ++j) {
                if (!is_prime(grid[i][j])) {
                    result.push_back(grid[i][j]);
                }
            }
        } else {
            // Traverse right to left
            for (int j = N - 1; j >= 0; --j) {
                if (!is_prime(grid[i][j])) {
                    result.push_back(grid[i][j]);
                }
            }
        }
    }

    if (result.empty()) {
        std::cout << -1 << std::endl;
    } else {
        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) std::cout << " ";
            std::cout << result[i];
        }
        std::cout << std::endl;
    }
}


int main() {
    int M, N;
    std::cin >> M >> N;
    std::vector<std::vector<int>> grid(M, std::vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> grid[i][j];
        }
    }
    zigzag_traversal(M, N, grid);
    return 0;
}
