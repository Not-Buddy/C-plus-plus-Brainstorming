class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  	unordered_map<int,int> Hash{};
	Hash.reserve(nums.size());
	for(int i{};i<nums.size();i++)
	{
		int diff = target - nums[i];
		if(Hash.find(diff)!=Hash.end())
		{
			return {Hash[diff],i};
		}
		Hash[nums[i]]=i;
	}
	return {};
    }
};
