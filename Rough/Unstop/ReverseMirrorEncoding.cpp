#include <iostream>
#include <string>

void decode_message(const std::string& encoded) {
    std::string decoded;
    for (size_t i = 0; i < encoded.size(); ++i) {
        char c = encoded[i];
        if (c >= 'a' && c <= 'n') {
            // Reverse in first half: 'a'->'n', 'b'->'m', ..., 'n'->'a'
            decoded += ('n' - (c - 'a'));
        } else if (c >= 'o' && c <= 'z' && i + 1 < encoded.size() && encoded[i + 1] == '#') {
            // Reverse in second half: 'o#'->'z', ..., 'z#'->'o'
            decoded += ('z' - (c - 'o'));
            ++i; // Skip the '#'
        }
        // For valid input, no need to handle else
    }
    std::cout << decoded << std::endl;
}


int main() {
    std::string encoded;
    std::getline(std::cin, encoded);
    
    // Call user logic function and print the output
    decode_message(encoded);
    return 0;
}
