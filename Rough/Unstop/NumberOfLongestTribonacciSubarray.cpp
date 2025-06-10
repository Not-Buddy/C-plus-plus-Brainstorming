#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int MOD = 1000000007;

unordered_set<int> generate_tribonacci_numbers(int max_value) {
    vector<int> tribonacci = {0, 1, 1};
    unordered_set<int> trib_set = {0, 1};
    
    while (true) {
        int next_value = tribonacci[tribonacci.size() - 1] + 
                        tribonacci[tribonacci.size() - 2] + 
                        tribonacci[tribonacci.size() - 3];
        if (next_value > max_value) {
            break;
        }
        tribonacci.push_back(next_value);
        trib_set.insert(next_value);
    }
    return trib_set;
}

int count_tribonacci_subarrays(const vector<int>& arr) {
    int max_value = 100000;
    unordered_set<int> tribonacci_set = generate_tribonacci_numbers(max_value);
    long long count = 0;
    int current_length = 0;

    for (int num : arr) {
        if (tribonacci_set.find(num) != tribonacci_set.end()) {
            current_length++;
        } else {
            if (current_length > 0) {
                count += (long long)current_length * (current_length + 1) / 2;
                count %= MOD;
            }
            current_length = 0;
        }
    }

    // If there was a valid segment at the end
    if (current_length > 0) {
        count += (long long)current_length * (current_length + 1) / 2;
        count %= MOD;
    }

    return (int)count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << count_tribonacci_subarrays(arr) << "\n";
    return 0;
}
