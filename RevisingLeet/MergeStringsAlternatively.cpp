class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string output{};
        
        int length = max(word1.size(), word2.size());
        int i{0};
        while(i<length)
        {
            if(i<word1.size())
                output += word1[i];
            if(i<word2.size())
                output += word2[i];
            i++;
        }
        return output;
    }
};
