class Solution {
public:

    int countZeros(vector<int> &nums)
    {
        int n = nums.size();
        int numZeros{};
        for(int i{0};i<n;i++)
        {
            if(nums[i]==0)
            {
                nums.erase(nums.begin()+i);
                numZeros++;
                i--;
                n--;
            }
        }
        return numZeros;
    }
    void moveZeroes(vector<int>& nums) {
        int zeros = countZeros(nums);
        if(zeros==0)
        {
            return;
        }
        else 
        {
            for(int i{0};i<zeros;i++)
            {
                nums.push_back(0);
            }
        }
        return;
    }
};
