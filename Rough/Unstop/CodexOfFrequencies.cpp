#include <iostream>
#include <string>

#include <vector>
#include <algorithm>

void user_logic(const std::string& s) {
    std::vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    // Collect odd frequencies and their corresponding characters
    std::vector<std::pair<int, char>> odds;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 == 1)
            odds.push_back({freq[i], static_cast<char>('a' + i)});
    }

    // Sort by frequency descending, then by character ascending
    std::sort(odds.begin(), odds.end(), [](const std::pair<int, char>& a, const std::pair<int, char>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    if (odds.empty()) {
        std::cout << -1 << std::endl;
    } else if (odds.size() < 3) {
        // Print the smallest odd frequency (lex smallest character if tie)
        auto min_it = std::min_element(odds.begin(), odds.end(), [](const std::pair<int, char>& a, const std::pair<int, char>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        std::cout << min_it->second << " " << min_it->first << std::endl;
    } else {
        int product = 1;
        for (int i = 0; i < 3; ++i) {
            std::cout << odds[i].second << " " << odds[i].first << std::endl;
            product *= odds[i].first;
        }
        std::cout << product << std::endl;
    }
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    
    user_logic(s);
    
    return 0;
}
