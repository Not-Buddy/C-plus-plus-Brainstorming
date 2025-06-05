#include <iostream>
#include <vector>
using namespace std;

int user_logic(int n, vector<int>& arr, vector<int>& b);

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int result = user_logic(n, arr, b);
    cout << result << endl;
    return 0;
}


#include <algorithm>
using namespace std;

int user_logic(int n, vector<int>& arr, vector<int>& b) {
    // Create sorted copies for binary search
    vector<int> sorted_arr = arr;
    vector<int> sorted_b = b;
    sort(sorted_arr.begin(), sorted_arr.end());
    sort(sorted_b.begin(), sorted_b.end());
    
    int interest_value_1 = 0;
    int interest_value_2 = 0;
    
    // Calculate interest value for syllabus 1 using binary search
    for (int i = 0; i < n; i++) {
        interest_value_1 += upper_bound(sorted_b.begin(), sorted_b.end(), arr[i]) - sorted_b.begin();
    }
    
    // Calculate interest value for syllabus 2 using binary search
    for (int i = 0; i < n; i++) {
        interest_value_2 += upper_bound(sorted_arr.begin(), sorted_arr.end(), b[i]) - sorted_arr.begin();
    }
    
    return max(interest_value_1, interest_value_2);
}

