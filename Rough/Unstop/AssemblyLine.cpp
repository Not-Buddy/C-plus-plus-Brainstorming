#include <iostream>
#include <vector>

#include <algorithm>

void find_student_positions(int n, std::vector<int>& heights, int k, std::vector<int>& queries, std::vector<int>& results) {
    // heights is already sorted in ascending order
    for (int i = 0; i < k; ++i) {
        int H = queries[i];
        // Find the first position where heights[pos] >= H
        auto it = std::lower_bound(heights.begin(), heights.end(), H);
        results[i] = it - heights.begin();
    }
}


int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> heights[i];
    }
    std::cin >> k;
    std::vector<int> queries(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> queries[i];
    }
    std::vector<int> results(k);
    find_student_positions(n, heights, k, queries, results);
    for (int i = 0; i < k; ++i) {
        std::cout << results[i] << std::endl;
    }
    return 0;

