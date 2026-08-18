class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        std::vector<int> ans(n,0);
        
        for(int i{0}; i<n; i++)
        {
            for(int j{i + 1}; j<n; j++)
            {
                if(temps[j]>temps[i])
                {    
                    ans[i] = j - i;
                    break;
                }
            }
        }

    return ans;
    }
};
