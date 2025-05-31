#include <iostream>
#include <string>

void decode_sequences(int n, const std::string& word1, int m, const std::string& word2) {
    std::string result;
    int i = 0, j = 0;
    while (i < n && j < m) {
        result += word1[i++];
        result += word2[j++];
    }
    // Append the rest of the longer sequence
    while (i < n) result += word1[i++];
    while (j < m) result += word2[j++];
    std::cout << result << std::endl;
}


int main() {
    int n, m;
    std::string word1, word2;
    std::cin >> n >> word1 >> m >> word2;
    decode_sequences(n, word1, m, word2);
    return 0;
}
