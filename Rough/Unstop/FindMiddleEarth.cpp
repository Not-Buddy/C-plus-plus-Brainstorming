#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // for std::fixed and std::setprecision

void find_middle_earth(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    
    if (m > n) {
        find_middle_earth(nums2, nums1);
        return;
    }
    
    int imin = 0, imax = m, half_len = (m + n + 1) / 2;
    
    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = half_len - i;
        
        if (i < m && nums2[j-1] > nums1[i]) {
            imin = i + 1;
        } else if (i > 0 && nums1[i-1] > nums2[j]) {
            imax = i - 1;
        } else {
            int max_of_left;
            if (i == 0) {
                max_of_left = nums2[j-1];
            } else if (j == 0) {
                max_of_left = nums1[i-1];
            } else {
                max_of_left = std::max(nums1[i-1], nums2[j-1]);
            }
            
            if ((m + n) % 2 == 1) {
                std::cout << std::fixed << std::setprecision(1) << static_cast<double>(max_of_left) << std::endl;
                return;
            }
            
            int min_of_right;
            if (i == m) {
                min_of_right = nums2[j];
            } else if (j == n) {
                min_of_right = nums1[i];
            } else {
                min_of_right = std::min(nums1[i], nums2[j]);
            }
            
            double median = (max_of_left + min_of_right) / 2.0;
            std::cout << std::fixed << std::setprecision(1) << median << std::endl;
            return;
        }
    }
}


int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<int> nums1(m);
    std::vector<int> nums2(n);
    for (int i = 0; i < m; ++i) {
        std::cin >> nums1[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> nums2[i];
    }
    find_middle_earth(nums1, nums2);
    return 0;
}
