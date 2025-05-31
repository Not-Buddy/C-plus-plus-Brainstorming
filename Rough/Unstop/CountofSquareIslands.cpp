#include <iostream>
#include <vector>
int count_square_sub_islands(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    int total = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = std::min(dp[i-1][j], std::min(dp[i][j-1], dp[i-1][j-1])) + 1;

                }
                total += dp[i][j];
            }
        }
    }
    return total;
}


int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int result = count_square_sub_islands(matrix);
    std::cout << result << std::endl;

    return 0;
}
