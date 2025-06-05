#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string input;
    getline(cin, input);
    
    // Split the input into words
    vector<string> words;
    stringstream ss(input);
    string word;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    // Create pairs of (position, word_without_digit)
    vector<pair<int, string>> wordPairs;
    
    for (const string& w : words) {
        // Extract the digit (last character) and the word (all except last)
        int position = w.back() - '0';  // Convert char digit to int
        string originalWord = w.substr(0, w.length() - 1);
        wordPairs.push_back({position, originalWord});
    }
    
    // Sort by position
    sort(wordPairs.begin(), wordPairs.end());
    
    // Reconstruct the sentence
    string result = "";
    for (int i = 0; i < wordPairs.size(); i++) {
        if (i > 0) result += " ";
        result += wordPairs[i].second;
    }
    
    cout << result << endl;
    
    return 0;
}
