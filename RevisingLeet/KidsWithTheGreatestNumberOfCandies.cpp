class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();
        std::vector<bool> output(n, false);

        int max_in_candies = *max_element(candies.begin(), candies.end());

        for(int i{0};i<n;i++)
        {
            int curMax = (candies[i] + extraCandies);

            if(curMax >= max_in_candies)
                output[i] = true;
        }

        return output;
    }
};
