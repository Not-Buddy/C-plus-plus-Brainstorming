#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int FindMaximum(const std::vector<int> subarray)
{
    int max{INT_MIN};
    int n=subarray.size();
    for(int i{0};i<n;i++)
    {
        if(max<subarray[i])
            max=subarray[i];
    }
    return max;
}

vector<int> find_tallest(int N, int K, vector<int> height) {
    vector<int> result;
    // Write your logic here.

    for(int i{0};i<=N-K;i++)
    {
        std::vector<int> subarray{};
        for(int j{i};j<i+K;j++)
        {
            subarray.push_back(height[j]);
        }
        int maxxed=FindMaximum(subarray);
        result.push_back(maxxed);
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
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
