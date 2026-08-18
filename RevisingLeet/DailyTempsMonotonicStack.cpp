class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        std::vector<int> ans(n,0);
        std::stack<int> st{};

        for(int i{0}; i<n; i++)
        {
            while(!st.empty() && temps[st.top()] < temps[i])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

    return ans;
    }
};
