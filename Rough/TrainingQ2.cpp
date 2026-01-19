#include <bits/stdc++.h>
using namespace std;

// nums is modified in-place
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int pos = 0;                  // position to place next non-zero

    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) {
            swap(nums[pos], nums[i]);
            pos++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    for (int x : nums) cout << x << " ";
    // output: 1 3 12 0 0
}

