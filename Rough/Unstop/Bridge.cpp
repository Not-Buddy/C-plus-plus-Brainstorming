#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MOD = 998244353;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    // Store unusable edges
    set<pair<int, int>> unusable;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        unusable.insert({min(u, v), max(u, v)});
    }
    
    // DP: dp[step][city] = number of ways to reach city in step steps
    vector<vector<long long>> dp(K + 1, vector<long long>(N + 1, 0));
    dp[0][1] = 1; // Start at city 1
    
    for (int step = 1; step <= K; step++) {
        for (int city = 1; city <= N; city++) {
            // Sum over all previous cities that can reach current city
            for (int prev = 1; prev <= N; prev++) {
                if (prev != city) {
                    // Check if road exists (not unusable)
                    pair<int, int> edge = {min(prev, city), max(prev, city)};
                    if (unusable.find(edge) == unusable.end()) {
                        // There's a road from prev to city
                        dp[step][city] = (dp[step][city] + dp[step-1][prev]) % MOD;
                    }
                }
            }
        }
    }
    
    cout << dp[K][1] << endl;
    return 0;
}
