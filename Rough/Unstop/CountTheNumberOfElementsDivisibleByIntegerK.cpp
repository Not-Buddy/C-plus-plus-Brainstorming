#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

void generate_combinations(vector<int>& arr, vector<bool>& visited, string current, set<int>& unique_numbers);

int main() {
    int K, N;
    cin >> K;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    set<int> unique_numbers;
    vector<bool> visited(N, false);

    // Generate all combinations using backtracking
    generate_combinations(arr, visited, "", unique_numbers);

    // Count numbers divisible by K
    int count = 0;
    for (int num : unique_numbers) {
        if (num % K == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

void generate_combinations(vector<int>& arr, vector<bool>& visited, string current, set<int>& unique_numbers) {
    // User needs to implement the logic here
    if (!current.empty()) {
        unique_numbers.insert(stoi(current));
    }

    // Explore all possibilities
    for (int i = 0; i < arr.size(); ++i) {
        if (!visited[i]) {
            visited[i] = true; // Mark as visited
            generate_combinations(arr, visited, current + to_string(arr[i]), unique_numbers); // Include current element
            visited[i] = false; // Backtrack
        }
    }
}