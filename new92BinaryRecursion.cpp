#include <iostream>
#include <vector>

using namespace std;

// A recursive binary search function. It returns
// location of x in given vector arr[low..high] is present,
// otherwise -1
int binarySearch(const vector<int>& arr, int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x) {
            return mid;
        }

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x) {
            return binarySearch(arr, low, mid - 1, x);
        }

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, high, x);
    }
    return -1;
}

// Driver code
int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int query = 90;
    int n = arr.size();

    cout<<"Enter the element that you want to search or by default 90 will be searched"<<"\n";
    cin>>query;
    int result = binarySearch(arr, 0, n - 1, query);
    if (result == -1) {
        cout << "Element is not present in vector";
    } else {
        cout << "Element is present at index " << result;
    }
    return 0;
}
