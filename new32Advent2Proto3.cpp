#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string input = "apple,orange,banana,grape";
    char separator = ',';

    std::istringstream ss(input);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, separator)) {
        tokens.push_back(token);
    }

    // Display the resulting tokens
    for (const auto& t : tokens) {
        std::cout << t << std::endl;
    }

    return 0;
}

