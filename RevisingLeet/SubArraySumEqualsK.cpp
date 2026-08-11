
#include <unordered_map>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
	    std::unordered_map<int,int> HashMap{};
	    int count = 0;
	    int sum = 0;
	    int n = nums.size();
	    
	    HashMap[0]=1;

	
	    for(int i{0};i<n;i++)
	    {
		sum += nums[i];

		if(HashMap.find(sum-k) != HashMap.end())
			count += HashMap[sum-k];
		HashMap[sum]++;
	    }
	
	return count;

    }
};
