#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

bool is_perfect_square_of_prime(int x) {
    if (x < 4) return false; // 2^2 = 4 is the smallest
    int root = std::sqrt(x);
    if (root * root != x) return false;
    return is_prime(root);
}

void check_qualification(const std::string &word) {
    int vowel_count = 0, consonant_count = 0;
    for (char c : word) {
        char lc = std::tolower(c);
        if (std::isalpha(c)) {
            if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
                ++vowel_count;
            else
                ++consonant_count;
        }
    }
    if (vowel_count >= 2 && consonant_count > 0 && is_perfect_square_of_prime(consonant_count))
        std::cout << "Qualify" << std::endl;
    else
        std::cout << "Disqualify" << std::endl;
}


int main() {
    std::string word;
    std::getline(std::cin, word);
    
    check_qualification(word);
    return 0;
}

