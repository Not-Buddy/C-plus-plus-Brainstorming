class Solution {
public:
    int reversePairs(vector<int>& nums) 
    {
        int count{};
        for(int i{0};i<nums.size();i++)
        {
            for(int j{0};j<nums.size();j++)
            {
                if(i<j && (long long)nums[i] > 2LL * (long long)nums[j])
                    count++;
            }
        }   
        return count;
    }
};
