#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> peaks(n);
    for (int i = 0; i < n; ++i) {
        cin >> peaks[i];
    }

    vector<int> prefix_min(n), suffix_max(n);

    // Compute prefix minimums
    prefix_min[0] = peaks[0];
    for (int i = 1; i < n; ++i) {
        prefix_min[i] = min(prefix_min[i-1], peaks[i]);
    }

    // Compute suffix maximums
    suffix_max[n-1] = peaks[n-1];
    for (int i = n-2; i >= 0; --i) {
        suffix_max[i] = max(suffix_max[i+1], peaks[i]);
    }

    // Calculate the sum of wish values
    int total_wish = 0;
    for (int i = 0; i < n; ++i) {
        total_wish += abs(suffix_max[i] - prefix_min[i]);
    }

    cout << total_wish << endl;
    return 0;
}

