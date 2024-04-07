#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Define a vector of pairs
    std::vector<std::pair<int, int>> vec = {{3, 5}, {1, 8}, {2, 4}, {5, 2}};

    // Sort the vector based on the first element of each pair
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    // Display the sorted vector
    std::cout << "Sorted vector based on the first element of each pair:" << std::endl;
    for (const auto& p : vec) {
        std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
    }

    return 0;
}

