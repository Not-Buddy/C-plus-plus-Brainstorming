class Solution {
public:
    string reverseVowels(string s) {
        std::stack<char> st{};
        std::string ans=s;
        for(int i{0};i<s.size();i++)
        {
            int ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                st.push(ch);
            }
        }

        for(int i{0};i<ans.size();i++)
        {
            int ch = ans[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                ans[i]=st.top();
                st.pop();
            }
        }      

    return ans;
    }
};
