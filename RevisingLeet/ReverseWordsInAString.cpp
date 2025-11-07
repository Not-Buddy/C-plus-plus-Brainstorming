class Solution {
public:
    string reverseWords(string s) {
        std::vector<string> words{};
        std::string temp{};
        for(int i{0};i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                if(!temp.empty()){words.push_back(temp);
                temp.clear();}
            }
            else 
            {
                temp+=s[i];
            }
        }
        if(!temp.empty())
            words.push_back(temp); //If last word exists
        reverse(words.begin(),words.end());
        std::string reved{};
        
        for(int i{0};i<words.size();i++)
        {
            reved += words[i];
            if(i<words.size()-1)
                reved+=" ";
        }

        return reved;
    }
};
