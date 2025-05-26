#include <iostream>
#include <vector>
#include <climits>
#include <algorihm>
using namespace std;

// Placeholder function for user logic
int findLargestNumber(vector<int>& arr) {
    // Write your logic here
    sort(arr.begin(),arr.end());
    int out=arr[1]*10+arr[0];
    return out; // Placeholder return value
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // Call user logic function and print the output
    int result = findLargestNumber(arr);
    cout << result << endl;
    return 0;
}
