#include <iostream>
#include <string>
#include <algorithm>

int user_logic(std::string s) {
    int max_length = 0;
    int current_length = 0;
    bool in_word = false;
    
    for (char c : s) {
        if (c == ',' || c == '.') {
            // End of sentence - count the last word if we're in one
            if (in_word) {
                current_length++;
                in_word = false;
            }
            // Update max and reset for next sentence
            max_length = std::max(max_length, current_length);
            current_length = 0;
        } 
        else if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            // Whitespace - end current word if we're in one
            if (in_word) {
                current_length++;
                in_word = false;
            }
        } 
        else {
            // Character - we're in a word
            in_word = true;
        }
    }
    
    // Handle the last sentence if it doesn't end with delimiter
    if (in_word) {
        current_length++;
    }
    max_length = std::max(max_length, current_length);
    
    return max_length;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    
    int result = user_logic(s);
    std::cout << result << std::endl;
    return 0;
}
