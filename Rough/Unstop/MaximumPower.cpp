#include <iostream>
#include <vector>
using namespace std;

bool can_partition(vector<int>& arr) {
    int total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }

    if (total_sum % 2 != 0) {
        return false;
    }

    int target = total_sum / 2;
    int n = arr.size();
    
    vector<bool> dp(target + 1, false);
    dp[0] = true; 
    for (int i = 0; i < n; ++i) {
        for (int j = target; j >= arr[i]; --j) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    return dp[target];
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    if (can_partition(arr)) {
        int total_sum = 0;
        for (int i = 0; i < N; ++i) {
            total_sum += arr[i];
        }
        cout << total_sum / 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}