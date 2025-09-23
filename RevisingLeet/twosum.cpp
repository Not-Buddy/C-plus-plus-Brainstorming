class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
            int n = nums.size();
            for(int i{};i<n;i++)
            {
                for(int j{};j<n;j++)
                {
                    if(i!=j&&(nums[i]+nums[j]==target))
                        return {i,j};
                }
            }
            return {};
    }
};