#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Helper function to calculate Fibonacci number
long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// Helper function to check if array can be partitioned into k parts with max sum <= mid
bool canPartition(vector<int>& arr, int k, long long mid) {
    int count = 1;
    long long currentSum = 0;
    
    for (int num : arr) {
        if (currentSum + num > mid) {
            count++;
            currentSum = num;
            if (count > k) {
                return false;
            }
        } else {
            currentSum += num;
        }
    }
    return true;
}

int peculiarNumber(int n, int k, vector<int>& arr) {
    // Step 1: Replace each element with absolute difference between element and index
    vector<int> replacedArr(n);
    for (int i = 0; i < n; i++) {
        replacedArr[i] = abs(arr[i] - i);
    }
    
    // Step 2: Binary search for minimum possible maximum sum
    long long low = *max_element(replacedArr.begin(), replacedArr.end());
    long long high = 0;
    for (int num : replacedArr) {
        high += num;
    }
    
    while (low < high) {
        long long mid = (low + high) / 2;
        if (canPartition(replacedArr, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    // Step 3: Calculate peculiar number
    long long x = low;
    if (x < 100) {
        return fibonacci(x);
    } else {
        return x;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Call user logic function and print the output
    int result = peculiarNumber(n, k, arr);
    cout << result << endl;

    return 0;
}
