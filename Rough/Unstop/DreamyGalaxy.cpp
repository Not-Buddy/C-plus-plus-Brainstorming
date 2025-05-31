#include <iostream>
#include <vector>

int calculate_max_moons(int n, int m, const std::vector<std::vector<int>>& moons) {
    int max_total = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += moons[i][j];
        }
        if (sum > max_total) max_total = sum;
    }
    return max_total;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> moons(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> moons[i][j];
        }
    }
    
    int result = calculate_max_moons(n, m, moons);
    std::cout << result << std::endl;
    return 0;
}

