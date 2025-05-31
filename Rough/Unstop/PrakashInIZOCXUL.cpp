#include <iostream>
#include <vector>
#include <string>
std::vector<int> count_substrings(const std::string& S, int K) {
    int n = S.size();
    std::vector<int> counts;
    for (int len = 2; len <= K; ++len) {
        int count = 0;
        for (int i = 0; i + len <= n; ++i) {
            bool unique = true;
            std::vector<bool> seen(26, false);
            for (int j = i; j < i + len; ++j) {
                if (seen[S[j] - 'a']) {
                    unique = false;
                    break;
                }
                seen[S[j] - 'a'] = true;
            }
            if (unique) count++;
        }
        counts.push_back(count);
    }
    return counts;
}


int main() {
    std::string S;
    int K;
    std::cin >> S;
    std::cin >> K;
    std::vector<int> result = count_substrings(S, K);
    for (int count : result) {
        std::cout << count << std::endl;
    }
    return 0;
}
