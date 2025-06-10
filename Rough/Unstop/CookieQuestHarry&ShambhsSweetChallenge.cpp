#include <bits/stdc++.h>
using namespace std;

int maximizeNutritionalValue(int n, int m, int k, vector<int> &price, vector<int> &nutrition) {
    // dp[i][j][l]: max nutrition using first i fruits, budget j, l coupons left
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
    
    for (int i = 1; i <= n; i++) {
        int p = price[i-1];
        int nutr = nutrition[i-1];
        int half_p = p / 2;  // Floor division for coupon price
        
        for (int j = 0; j <= m; j++) {
            for (int l = 0; l <= k; l++) {
                // Option 1: Don't take this fruit
                dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][l]);
                
                // Option 2: Take this fruit without coupon
                if (j >= p) {
                    dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-p][l] + nutr);
                }
                
                // Option 3: Take this fruit with coupon
                if (l > 0 && j >= half_p) {
                    dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-half_p][l-1] + nutr);
                }
            }
        }
    }
    
    // Find the maximum nutrition possible across all budget and coupon combinations
    int max_nutrition = 0;
    for (int j = 0; j <= m; j++) {
        for (int l = 0; l <= k; l++) {
            max_nutrition = max(max_nutrition, dp[n][j][l]);
        }
    }
    
    return max_nutrition;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> price(n), nutrition(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> nutrition[i];
    }

    int result = maximizeNutritionalValue(n, m, k, price, nutrition);
    cout << result << endl;

    return 0;
}
