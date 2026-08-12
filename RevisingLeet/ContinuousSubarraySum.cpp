#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        std::unordered_map<int,int> remainder_map;
        remainder_map[0] = -1;

        int sum = 0;
        int n = nums.size();
        for(int i{0};i<n;i++)
        {
            sum += nums[i];
            int rem = sum % k;

            if(remainder_map.find(rem) != remainder_map.end())
            {
                if(i-remainder_map[rem] >= 2)
                    return true;
            }
            else 
                remainder_map[rem] = i;
        }

        return false;
    }
};
