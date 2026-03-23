class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if(nums.empty()) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int final_max = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i];

            int temp_max = max({curr, max_so_far * curr, min_so_far * curr});
            min_so_far = min({curr, max_so_far * curr, min_so_far * curr});

            max_so_far = temp_max;
            final_max = max(final_max, max_so_far);

        }
        
        return final_max;
    }
};
