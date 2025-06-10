#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int s = 1; (s * (s - 1)) / 2 <= i; ++s) {
            int p = (s * (s - 1)) / 2;
            if (i - p >= 0) {
                dp[i] = std::min(dp[i], dp[i - p] + s);
            }
        }
    }

    std::cout << dp[n] << ' ' << ((long long) dp[n] * (dp[n] - 1)) / 2 - n << '\n';
}

int main() {
    solve();
    return 0;
}