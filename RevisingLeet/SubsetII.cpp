class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       std::set<std::vector<int>> uniq_subsets;
        std::vector<int> current;
        std::sort(nums.begin(),nums.end());
        backtrack(nums,0,current,uniq_subsets);
        return std::vector<std::vector<int>> (uniq_subsets.begin(),uniq_subsets.end());                
   }
   void backtrack(const std::vector<int> &nums,int start, std::vector<int> &current,
   std::set<std::vector<int>> &uniq_subsets)
   {
    uniq_subsets.insert(current);
    for(int i = start; i<nums.size();i++)
    {
        current.push_back(nums[i]);
        backtrack(nums,i+1,current,uniq_subsets);
        current.pop_back();
    }
   }
}; 
