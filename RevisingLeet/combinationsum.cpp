class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result{};
        vector<int> comb{};
        solve(result, comb, 0, candidates, 0, target);
        return result;
    }

    void solve(vector<vector<int>> &result, vector<int> &comb, int idx, vector<int> &candidates,int total, int target)
    {
        if(total == target)
        {
            result.push_back(comb);
            return;
        }

        if(total > target || idx >= candidates.size())
            return;
        
        comb.push_back(candidates[idx]);
        solve(result, comb,idx, candidates, total + candidates[idx], target);
        
        comb.pop_back();
        solve(result, comb,idx+1, candidates,total, target);
        
    }
};