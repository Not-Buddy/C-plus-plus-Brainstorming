#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) 
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int &num : nums) cin >> num;
        
        sort(nums.begin(), nums.end());
        
        int left = 0, right = n - 1, score = 0;
        while (left < right) 
        {
            if (nums[left] + nums[right] == k) 
            {
                score++;
                left++;
                right--;
            } 
            else if (nums[left] + nums[right] < k) 
            {
                left++;
            } 
            else 
            {
                right--;
            }
        }
        
        cout << score << '\n';
    }
    
    return 0;
}
