class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> Hash{};
        Hash.reserve(nums.size());
        for(int i:nums)
            Hash[i]++;

        std::vector<int> num{};
        for(auto k:Hash)
        {
            if(k.second == 1)
            {
                num.push_back(k.first);
            }
            if(num.size()==2)
                break;
        }

        return num;
  
    }
};
