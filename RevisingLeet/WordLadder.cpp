class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        
        if(wordSet.find(endWord) == wordSet.end())
            return 0;

        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty())
        {
            auto [currWord, step] = q.front();
            q.pop();

            for(int i{0}; i < currWord.length(); i++)
            {
                char origChar = currWord[i];

                for(char c = 'a'; c <= 'z'; c++)
                {
                    if(c == origChar) continue;

                    currWord[i] = c;

                    if(currWord == endWord)
                        return step + 1;

                    if(wordSet.find(currWord) != wordSet.end())
                    {
                        q.push({currWord, step + 1});
                        wordSet.erase(currWord);
                    }
                } 
                currWord[i] = origChar;
            }
        }
        return 0;
    }
};
