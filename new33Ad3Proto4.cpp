#include <iostream>
#include <string>

bool hasSpecialCharactersExceptDot(const std::string& str) {
    for (char ch : str) {
        // Check if the character is a special character (excluding dot)
        if (!std::isalnum(ch) && ch != '.') {
            return true;
        }
    }
    return false;
}

int main() {
    // Example usage
    std::string testString1 = "....*585..30....217*616..........$...................../....$.................447...........381..................+..........973.............";       // No special characters
    std::string testString2 = "Special@Char";   // Contains special character '@'
    std::string testString3 = "Dot.Is.Fine";    // Contains dots, but no other special characters

    if (hasSpecialCharactersExceptDot(testString1)) {
        std::cout << "String 1 has special characters (except dot).\n";
    } else {
        std::cout << "String 1 is fine.\n";
    }

    if (hasSpecialCharactersExceptDot(testString2)) {
        std::cout << "String 2 has special characters (except dot).\n";
    } else {
        std::cout << "String 2 is fine.\n";
    }

    if (hasSpecialCharactersExceptDot(testString3)) {
        std::cout << "String 3 has special characters (except dot).\n";
    } else {
        std::cout << "String 3 is fine.\n";
    }

    return 0;
}

