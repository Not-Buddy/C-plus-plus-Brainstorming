class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i{0};i<n;i++)
        {
            int currSum{};
            for(int j=i;j<n;j++)
                currSum+=nums[j],ans = max(ans,currSum);
        }
        return ans;
    }
};
