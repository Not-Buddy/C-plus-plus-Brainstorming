class Solution {
public:
    int findMin(vector<int>& nums) {

        int point{-1};
        for(int i{0};i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {    
                point = i;
                break;
            }
        }

        if(point == -1)
            return nums[0];
        else
        {
            return nums[point + 1];
        }

        return -1;
    }
};
