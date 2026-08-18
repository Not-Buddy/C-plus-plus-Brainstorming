class Solution {
public:

    int findNextGreater(int num, const std::vector<int> &nums2)
    {
        int i=0;
        while(nums2[i] != num)
            i++;
        i+=1;
        for (;i<nums2.size();i++)
        {
            if(nums2[i] > num)
                return nums2[i];
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        std::vector<int> ans{};
        
        for(int i{0}; i<n; i++)
        {
            int temp = findNextGreater(nums1[i], nums2);
            ans.push_back(temp);
        }

        return ans;
    }
};
