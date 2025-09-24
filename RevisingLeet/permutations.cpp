class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        perms(0,res,nums);
        return res;
    }
    void perms(int i, vector<vector<int>> &res, vector<int>&nums)
    {
        if(i==nums.size()) 
        {
            res.push_back(nums);
            return;
        }
        for(int j = i; j<nums.size();j++)
        {
            swap(num[j],nums[i]);
            perms(i+1,res,nums);
            swap(nums[i],nums[j]);
        }
    }
};