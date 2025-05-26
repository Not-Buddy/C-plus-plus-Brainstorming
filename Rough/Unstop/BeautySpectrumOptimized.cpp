#include <iostream>
#include <vector>
using namespace std;

vector<int> get_subarray_beauty(const vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> result;
    vector<int> count(101, 0); // Index 0 for -50, index 100 for 50

    // Initialize count for first window
    for (int i = 0; i < k; ++i) {
        if (nums[i] < 0) count[nums[i] + 50]++;
    }

    for (int i = 0; i <= n - k; ++i) {
        // Find x-th smallest negative
        int cnt = 0, val = 0;
        for (int j = 0; j < 50; ++j) { // Only negative numbers
            cnt += count[j];
            if (cnt >= x) {
                val = j - 50;
                break;
            }
        }
        if (cnt < x) val = 0;
        result.push_back(val);

        // Slide window
        if (i + k < n) {
            if (nums[i] < 0) count[nums[i] + 50]--;
            if (nums[i + k] < 0) count[nums[i + k] + 50]++;
        }
    }
    return result;
}

int main() {
    int k, x, n;
    cin >> k >> x >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int> result = get_subarray_beauty(nums, k, x);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    return 0;
}

