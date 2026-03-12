#include <vector>

using namespace std;



class Solution {

public:

    vector<int> elements_appearing_more_than_n_by_3(vector<int> nums) {

        // Write your solution here
        int n = nums.size();
        int candidate1 = 0, candidate2 = 1;
        int count1 = 0, count2 = 0;

        for(int num: nums)
        {
          if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

         count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }
        
        vector<int> result;
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);
        
        sort(result.begin(),result.end());

        return result;
    }

};
