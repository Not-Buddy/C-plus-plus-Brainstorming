#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> degree(N + 1, 0);
    
    // Count degree of each node
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    
    // Find node with degree N-1
    for (int i = 1; i <= N; i++) {
        if (degree[i] == N - 1) {
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}
