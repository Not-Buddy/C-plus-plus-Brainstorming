class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if(nums.empty()) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int final_max = nums[0];

        for(int i{1}; i<nums.size(); i++)
        {
        
            int curr = nums[i];

            auto [new_max, new_min] = make_pair(
                max({curr, max_so_far * curr, min_so_far * curr}),
                min({curr, max_so_far * curr, min_so_far * curr})
            );

            max_so_far = new_max;
            min_so_far = new_min;
            final_max = max(final_max, max_so_far);
        }
        
        return final_max;
    }
};
