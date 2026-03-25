class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        int sum1{0}, sum2{0};

        for(int i{0};i<nums.size();i+=2)
            sum1+=nums[i];

        for(int i{1};i<nums.size();i+=2)
            sum2+=nums[i];   
        return max(sum1, sum2);
    }
};
