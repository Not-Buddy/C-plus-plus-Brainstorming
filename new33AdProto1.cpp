#include <iostream>
#include <cctype>

bool isSpecialCharacter(char c) {
    return std::ispunct(static_cast<unsigned char>(c)) != 0;
}

bool hasSpecialCharacter(const std::string& str) {
    for (char c : str) {
        if (isSpecialCharacter(c)) {
            return true;  // Return true if any special character is found
        }
    }
    return false;  // No special characters found
}

int main() {
    std::string myString = "Hello . World!";

    if (hasSpecialCharacter(myString)) {
        std::cout << "The string contains at least one special character." << std::endl;
    } else {
        std::cout << "The string does not contain any special characters." << std::endl;
    }

    return 0;
}

