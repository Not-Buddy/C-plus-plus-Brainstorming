#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int computeScore(std::vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    // Precompute prefix second minima
    std::vector<int> prefix_second_min(n, INT_MAX);
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (i > 0) prefix_second_min[i] = min2;
        int val = arr[i];
        if (val < min1) {
            min2 = min1;
            min1 = val;
        } else if (val < min2) {
            min2 = val;
        }
    }

    // Precompute suffix second minima
    std::vector<int> suffix_second_min(n, INT_MAX);
    min1 = INT_MAX; min2 = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        if (i < n - 1) suffix_second_min[i] = min2;
        int val = arr[i];
        if (val < min1) {
            min2 = min1;
            min1 = val;
        } else if (val < min2) {
            min2 = val;
        }
    }

    // Calculate total score
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int before = (i == 0) ? INT_MAX : prefix_second_min[i];
        int after = (i == n - 1) ? INT_MAX : suffix_second_min[i];
        int score = std::max(arr[i] - before, arr[i] - after);
        total += score;
    }
    return total;
}

int main() {
    int n;
    std::cin >> n; // First input is the integer n
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i]; // Remaining input is the array of integers
    }

    // Call user logic function and print the output
    int result = computeScore(arr);
    std::cout << result << std::endl;
    return 0;
}

