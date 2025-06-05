#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_set>

using namespace std;

void generate(string current, int pos, vector<char>& chars, vector<string>& codes, int N) {
    if (pos == N) {
        codes.push_back(current);
        return;
    }
    for (char c : chars) {
        generate(current + c, pos + 1, chars, codes, N);
    }
}

void user_logic(int N, vector<char>& chars, int& total_codes, vector<string>& codes, pair<string, string>& min_diff_pair) {
    // Sort the characters in descending order
    sort(chars.begin(), chars.end(), [](char a, char b) {
        return a > b;
    });

    // Generate all possible codes (including duplicates)
    vector<string> all_codes;
    generate("", 0, chars, all_codes, N);

    // Remove duplicates
    unordered_set<string> unique_codes(all_codes.begin(), all_codes.end());
    codes.assign(unique_codes.begin(), unique_codes.end());

    // Sort codes in lexicographically descending order
    sort(codes.begin(), codes.end(), greater<string>());

    total_codes = codes.size();

    min_diff_pair = make_pair("", "");

    if (total_codes >= 2) {
        int min_diff = INT_MAX;
        for (int i = 0; i < codes.size() - 1; ++i) {
            const string& a = codes[i];
            const string& b = codes[i+1];
            int current_diff = 0;
            for (int j = 0; j < N; ++j) {
                current_diff += abs(a[j] - b[j]);
            }
            if (current_diff < min_diff) {
                min_diff = current_diff;
                min_diff_pair = make_pair(a, b);
            }
        }
    }
}

int main() {
    int N;
    vector<char> chars(3);
    
    cin >> N;
    for (int i = 0; i < 3; i++) {
        cin >> chars[i];
    }
    
    int total_codes;
    vector<string> codes;
    pair<string, string> min_diff_pair;
    
    // Call user logic function
    user_logic(N, chars, total_codes, codes, min_diff_pair);
    
    // Print the total number of unique product codes
    cout << total_codes << endl;
    
    // Print all product codes in lexicographically descending order
    for (const auto& code : codes) {
        cout << code << " ";
    }
    cout << endl;
    
    // Print the two product codes with the smallest ASCII difference
    if (min_diff_pair.first.empty() || min_diff_pair.second.empty()) {
        cout << -1 << endl;
    } else {
        cout << min_diff_pair.first << " " << min_diff_pair.second << endl;
    }
    
    return 0;
}
