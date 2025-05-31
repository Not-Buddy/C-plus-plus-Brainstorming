#include <iostream>
#include <vector>
#include <algorithm>

// Function to compute the maximum sum after partitioning
int max_sum_after_partitioning(std::vector<int>& arr, int k) {
    int n = arr.size();
    std::vector<int> dp(n + 1, 0); // dp[i] = max sum for first i elements
    for (int i = 1; i <= n; ++i) {
        int mx = 0;
        for (int len = 1; len <= k && i - len >= 0; ++len) {
            mx = std::max(mx, arr[i - len]);
            dp[i] = std::max(dp[i], dp[i - len] + mx * len);
        }
    }
    return dp[n];
}

// Sieve of Eratosthenes: count primes <= n
int sieve_of_eratosthenes(int n) {
    if (n < 2) return 0;
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            ++count;
            for (int j = 2 * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return count;
}

int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cin >> k;
    
    // Call user logic functions
    int max_sum = max_sum_after_partitioning(arr, k);
    int prime_count = sieve_of_eratosthenes(max_sum);
    
    // Print the result
    std::cout << prime_count << std::endl;
    return 0;
}

