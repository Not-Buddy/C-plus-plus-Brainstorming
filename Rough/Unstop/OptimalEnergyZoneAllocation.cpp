#include <iostream>
#include <vector>
using namespace std;

int countValidPartitions(vector<int>& arr) {
    int n = arr.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + arr[i];

    int total = 0;
    // Alpha: [0, i], Beta: [i+1, j], Gamma: [j+1, n-1]
    for (int k = 1; k <= n / 2; ++k) { // k = size of Alpha and Gamma
        int i = k - 1;
        int j = n - k - 1;
        if (i + 1 <= j && j < n - 1) { // Beta must have at least 1 element
            long long sum1 = prefix[i + 1] - prefix[0];
            long long sum2 = prefix[j + 1] - prefix[i + 1];
            long long sum3 = prefix[n] - prefix[j + 1];
            if (sum1 + sum3 > sum2)
                total++;
        }
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countValidPartitions(arr) << endl;
    return 0;
}

