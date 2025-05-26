#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Precompute Tribonacci numbers up to 1e5
unordered_set<int> generate_tribonacci(int limit = 100000) {
    unordered_set<int> trib;
    int t0 = 0, t1 = 1, t2 = 1;
    trib.insert(t0); trib.insert(t1); trib.insert(t2);
    while (true) {
        int t3 = t0 + t1 + t2;
        if (t3 > limit) break;
        trib.insert(t3);
        t0 = t1; t1 = t2; t2 = t3;
    }
    return trib;
}

void count_tribonacci_subarrays(int n, const vector<int>& arr) {
    unordered_set<int> trib = generate_tribonacci();
    long long total = 0;
    for (int start = 0; start < n; ++start) {
        for (int end = start; end < n; ++end) {
            int length = end - start + 1;
            // Check all elements are Tribonacci numbers
            bool all_trib = true;
            for (int i = start; i <= end; ++i) {
                if (!trib.count(arr[i])) {
                    all_trib = false;
                    break;
                }
            }
            if (!all_trib) break; // No longer possible to extend this subarray
            // For length >= 4, check recurrence
            bool valid = true;
            if (length >= 4) {
                for (int i = start + 3; i <= end; ++i) {
                    if (arr[i] != arr[i-1] + arr[i-2] + arr[i-3]) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) total++;
            else break; // No longer possible to extend this subarray
        }
    }
    cout << total << endl;
}
//1 test case fails
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    count_tribonacci_subarrays(n, arr);
    return 0;
}

