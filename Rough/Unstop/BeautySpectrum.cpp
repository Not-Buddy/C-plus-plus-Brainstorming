#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int nth_lowest_negative_value(const std::vector<int>& nums, int x) {
    std::vector<int> negatives;
    for (int val : nums) {
        if (val < 0) negatives.push_back(val);
    }
    if (negatives.size() < x) return 0;
    std::sort(negatives.begin(), negatives.end());
    return negatives[x-1];
}

std::vector<int> get_subarray_beauty(const std::vector<int>& nums, int k, int x) {
    // Write your logic here.
    std::vector<int> output{};
    int n=nums.size();

    for(int i{0};i<=n-k;i++)
    {
        std::vector<int> subarray{};
        for(int j{i};j<i+k;j++)
        {
            subarray.push_back(nums[j]);
        }
        //Function to get the nth lowest value in the subarray
        int low=nth_lowest_negative_value(subarray,x);
        output.push_back(low);
    }

    return output;
}

int main() {
    int k, x, n;
    std::cin >> k >> x >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::vector<int> result = get_subarray_beauty(nums, k, x);
    for (const auto& val : result) {
        std::cout << val << " ";
    }
    return 0;
}
