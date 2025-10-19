class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int consec{};
        int max_consec{};
        std::vector<int> storage{};
        for(int i{0};i<nums.size();i++)
        {
            if(nums[i]==1)
                consec++;
            else
            {
                if(max_consec <= consec)
                    max_consec = consec;
                consec = 0;
            }
        }
        return max(max_consec,consec);
    }
};
