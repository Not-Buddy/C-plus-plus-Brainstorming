class Solution {
public:
    int singleNumber(vector<int>& nums) {
       unordered_map<int,int> Hash{};
        Hash.reserve(nums.size());
        for(int i:nums)
            Hash[i]++;

        int num{};
        for(auto k:Hash)
        {
            if(k.second == 1)
            {
                num = k.first;
                break;
            }
        }

        return num;
    }
};
