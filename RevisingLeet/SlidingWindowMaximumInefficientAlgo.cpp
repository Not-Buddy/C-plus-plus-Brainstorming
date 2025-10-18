class Solution {
public:

    int GetMax(vector<int> &window)
    {
        int max = 0;
        for(int i{0};i<window.size();i++)
        {
            if(window[i]>max)
                max = window[i];
        }
        return max;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result{};
        for(int i{0};i<=nums.size()-k;i++)
        {
            std::vector<int> window{};
            for(int j{i};j<k+i;j++)
            {
                window.push_back(nums[j]);
            }
            int max_num = GetMax(window);
            result.push_back(max_num);
        }
        return result;

    }
};
