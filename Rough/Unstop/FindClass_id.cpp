#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(const vector<int>& A) {
    int n = A.size();
    
    // Check first element
    if (n >= 1 && A[0] >= A[1]) {
        return 0;
    }
    
    // Check middle elements
    for (int i = 1; i < n-1; i++) {
        if (A[i] >= A[i-1] && A[i] >= A[i+1]) {
            return i;
        }
    }
    
    // Check last element
    if (n >= 2 && A[n-1] >= A[n-2]) {
        return n-1;
    }
    
    return 0;  // Fallback (shouldn't reach here given constraints)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << peakIndexInMountainArray(arr) << endl;
    return 0;
}
