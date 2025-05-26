#include <iostream>
#include <vector>
using namespace std;

void can_partition_chocolates(int n, vector<int>& chocolates) {
    int total = 0;
    for (int x : chocolates) total += x;
    if (total % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    int target = total / 2;
    // DP: dp[s] = true if sum s is possible
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int x : chocolates) {
        for (int s = target; s >= x; --s) {
            if (dp[s - x]) dp[s] = true;
        }
    }
    cout << (dp[target] ? "YES" : "NO") << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> chocolates(n);
    for (int i = 0; i < n; ++i) {
        cin >> chocolates[i];
    }
    can_partition_chocolates(n, chocolates);
    return 0;
}

