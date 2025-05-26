#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> find_tallest(int N, int K, const vector<int>& height) {
    vector<int> left(N), right(N), result(N - K + 1);

    // Fill left array
    for (int i = 0; i < N; ++i) {
        if (i % K == 0)
            left[i] = height[i];
        else
            left[i] = max(left[i - 1], height[i]);
    }

    // Fill right array
    for (int i = N - 1; i >= 0; --i) {
        if (i == N - 1 || (i + 1) % K == 0)
            right[i] = height[i];
        else
            right[i] = max(right[i + 1], height[i]);
    }

    // Compute result
    for (int i = 0; i <= N - K; ++i) {
        result[i] = max(right[i], left[i + K - 1]);
    }

    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }
    vector<int> result = find_tallest(N, K, height);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}

