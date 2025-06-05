#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n < 4) {
        cout << n << endl;
        return 0;
    }
    
    // dp[i] = minimum deletions needed for first i characters
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        // Option 1: Delete current character
        dp[i] = dp[i-1] + 1;
        
        // Option 2: Keep current character
        if (i >= 4 && s.substr(i-4, 4) == "kill") {
            // Current position completes "kill", must delete at least 1 from "kill"
            dp[i] = min(dp[i], dp[i-4] + 1);
        } else {
            // Safe to keep current character
            dp[i] = min(dp[i], dp[i-1]);
        }
    }
    
    // Output the length of longest safe string
    cout << n - dp[n] << endl;
    
    return 0;
}
