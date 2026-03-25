class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];

        return max(robRange(nums, 0, nums.size()-2),
        robRange(nums, 1, nums.size()-1));
    }
    
    int robRange(vector<int> &nums, int l, int r)
    {
        int prev2 = 0, prev1 = 0;
        for(int i = l; i<=r; i++)
        {
            int curr = max(nums[i] + prev2, prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
