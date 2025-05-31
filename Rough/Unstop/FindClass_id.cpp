#include <iostream>
#include <vector>
using namespace std;

// Function declaration
int peakIndexInMountainArray(vector<int>& A) {
    int n = A.size();
    for (int i = 1; i < n - 1; ++i) {
        if (A[i] >= A[i-1] && A[i] >= A[i+1]) {
            return i;
        }
    }
    // For a mountain array, this will always return within the loop.
    return -1; // Just in case, though not needed by constraints.
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << peakIndexInMountainArray(arr) << endl;
    return 0;
}
