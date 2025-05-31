#include <iostream>
#include <string>

int user_logic(const std::string& s) {
    if (s.empty()) return 0; // Defensive: handle empty string
    char first_char = s[0];
    std::string lower;
    lower.reserve(s.size());
    for (char c : s) lower.push_back(std::tolower(c));

    int n = lower.size();
    bool is_palindrome = true;
    for (int i = 0; i < n / 2; ++i) {
        if (lower[i] != lower[n - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }
    if (is_palindrome)
        return n;
    else
        return int(first_char);
}


int main() {
    std::string s;
    std::getline(std::cin, s);

    // Call user logic function and print the output
    int result = user_logic(s);
    std::cout << result << std::endl;

    return 0;
}
