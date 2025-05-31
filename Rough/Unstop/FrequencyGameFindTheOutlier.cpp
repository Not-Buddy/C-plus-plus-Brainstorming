#include <iostream>
#include <vector>

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

int find_minority_element_index(int N, std::vector<int>& nums) {
    std::unordered_map<int, int> freq;
    std::unordered_map<int, int> first_occurrence;
    for (int i = 0; i < N; ++i) {
        freq[nums[i]]++;
        if (first_occurrence.count(nums[i]) == 0)
            first_occurrence[nums[i]] = i;
    }

    // Collect all frequencies
    std::vector<int> freq_list;
    for (const auto& p : freq) {
        freq_list.push_back(p.second);
    }
    std::sort(freq_list.begin(), freq_list.end());
    int m = freq_list.size();
    int median_freq = freq_list[m / 2]; // For both odd and even, this matches the sample

    // Find element(s) with frequency closest to median
    int min_diff = 1e9;
    std::vector<int> candidates;
    for (const auto& p : freq) {
        int diff = std::abs(p.second - median_freq);
        if (diff < min_diff) {
            min_diff = diff;
            candidates.clear();
            candidates.push_back(p.first);
        } else if (diff == min_diff) {
            candidates.push_back(p.first);
        }
    }

    // Among candidates, pick the smallest value
    int min_val = *std::min_element(candidates.begin(), candidates.end());

    // Among all occurrences of min_val, pick the first occurrence
    int idx = first_occurrence[min_val];

    return idx + 1; // 1-based indexing
}


int main() {
    int N;
    std::cin >> N;
    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    int result = find_minority_element_index(N, nums);
    std::cout << result << std::endl;

    return 0;
}
