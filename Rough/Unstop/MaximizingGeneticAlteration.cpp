#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxEnhancement(long long N, vector<long long>& dp) {
    if (N < 2) return N; // Base case: no splitting possible or beneficial
    if (dp[N] != -1) return dp[N]; // Return memoized result if available
    
    // Option 1: Keep N as is
    long long keep = N;
    
    // Option 2: Split into N/2, N/3, N/4 and sum their enhancements
    long long split = maxEnhancement(N / 2, dp) + 
                      maxEnhancement(N / 3, dp) + 
                      maxEnhancement(N / 4, dp);
    
    // Take the maximum of keeping or splitting
    dp[N] = max(keep, split);
    return dp[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    cin >> N;
    
    // Initialize DP array with -1 (uncomputed)
    vector<long long> dp(N + 1, -1);
    
    // Compute and output the maximum enhancement level for N
    cout << maxEnhancement(N, dp) << endl;
    
    return 0;
}
