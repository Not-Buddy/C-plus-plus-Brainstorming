class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        ort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};s
