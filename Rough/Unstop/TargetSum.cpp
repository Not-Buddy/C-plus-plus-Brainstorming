#include <iostream>
#include <vector>

#include <iostream>
#include <vector>

int user_logic(const std::vector<int>& nums, int target) {
    int total_sum = 0;
    for (int num : nums) {
        total_sum += num;
    }
    
    // If target is out of possible range, return 0
    if (abs(target) > total_sum) {
        return 0;
    }
    
    int n = nums.size();
    // dp[i][j] represents ways to get sum (j - total_sum) using first i numbers
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2 * total_sum + 1, 0));
    
    // Base case: one way to get sum 0 with 0 elements
    dp[0][total_sum] = 1;
    
    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2 * total_sum; j++) {
            if (dp[i-1][j] != 0) {
                // Add current number (+ sign)
                if (j + nums[i-1] <= 2 * total_sum) {
                    dp[i][j + nums[i-1]] += dp[i-1][j];
                }
                // Subtract current number (- sign)  
                if (j - nums[i-1] >= 0) {
                    dp[i][j - nums[i-1]] += dp[i-1][j];
                }
            }
        }
    }
    
    return dp[n][target + total_sum];
}


int main() {
    int n, target;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::cin >> target;
    int ways = user_logic(nums, target);
    std::cout << ways << std::endl;
    return 0;
}