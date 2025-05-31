#include <iostream>
#include <string>
using namespace std;

#include <algorithm>

bool is_subsequence(const std::string& s, const std::string& t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) ++j;
        ++i;
    }
    return j == t.size();
}

int find_smallest_day(std::string S, std::string T) {
    std::string bob = S;
    int day = 1;
    // To avoid infinite loop, set a reasonable max day (since S and T are <= 1000, this is safe)
    int max_days = 2 * T.size() + 10;
    while (day <= max_days) {
        if (is_subsequence(bob, T)) {
            return day;
        }
        std::reverse(bob.begin(), bob.end());
        bob += S;
        ++day;
    }
    // Should never reach here per constraints, but just in case
    return -1;
}


int main() {
    string S, T;
    cin >> S >> T;
    int result = find_smallest_day(S, T);
    cout << result << endl;
    return 0;
}
