class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int sum_of_nums{};
        for(auto i:nums)
        {
            sum_of_nums+=i;
        }
        return sum - sum_of_nums;

    }
};
