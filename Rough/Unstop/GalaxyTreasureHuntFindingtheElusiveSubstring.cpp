#include <iostream>
#include <string>

#include <unordered_map>
#include <climits>

int shortest_substring(const std::string& s, const std::string& t) {
    if (t.empty() || s.empty()) return -1;

    std::unordered_map<char, int> need, have;
    for (char c : t) need[c]++;

    int required = need.size();
    int formed = 0, left = 0, min_len = INT_MAX;

    // (window_start, window_length)
    int window_start = 0;

    for (int right = 0; right < s.size(); ++right) {
        char c = s[right];
        have[c]++;
        if (need.count(c) && have[c] == need[c])
            formed++;

        while (formed == required) {
            // Update minimum window
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                window_start = left;
            }
            // Try to contract from the left
            char lc = s[left];
            have[lc]--;
            if (need.count(lc) && have[lc] < need[lc])
                formed--;
            left++;
        }
    }
    return (min_len == INT_MAX) ? -1 : min_len;
}


int main() {
    std::string s, t;
    std::cin >> s >> t;
    int result = shortest_substring(s, t);
    std::cout << result << std::endl;
    return 0;
}

