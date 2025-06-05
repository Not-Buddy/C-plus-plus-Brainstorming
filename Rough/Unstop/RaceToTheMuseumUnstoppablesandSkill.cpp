#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class BipartiteMatching {
private:
    vector<vector<int>> graph;
    vector<int> match;
    vector<bool> used;
    int n, m;
    
    bool dfs(int v) {
        if (used[v]) return false;
        used[v] = true;
        
        for (int to : graph[v]) {
            if (match[to] == -1 || dfs(match[to])) {
                match[to] = v;
                return true;
            }
        }
        return false;
    }
    
public:
    BipartiteMatching(int n, int m) : n(n), m(m) {
        graph.resize(n);
        match.assign(m, -1);
    }
    
    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }
    
    void clearEdges() {
        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }
        match.assign(m, -1);
    }
    
    int maxMatching() {
        int result = 0;
        for (int v = 0; v < n; v++) {
            used.assign(n, false);
            if (dfs(v)) result++;
        }
        return result;
    }
};

long long calculateTime(long long unstoppable, long long spell, long long museum) {
    return abs(unstoppable - spell) + abs(spell - museum);
}

bool canFinishInTime(const vector<long long>& unstoppables, 
                     const vector<long long>& spells, 
                     long long museum, long long maxTime, int n) {
    
    BipartiteMatching bm(n, spells.size());
    
    // Add edges for valid assignments within time limit
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < spells.size(); j++) {
            if (calculateTime(unstoppables[i], spells[j], museum) <= maxTime) {
                bm.addEdge(i, j);
            }
        }
    }
    
    return bm.maxMatching() == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    long long p;
    cin >> n >> m >> p;
    
    vector<long long> unstoppables(n), spells(m);
    
    for (int i = 0; i < n; i++) {
        cin >> unstoppables[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> spells[i];
    }
    
    // Binary search on the answer
    long long left = 0, right = 0;
    
    // Calculate maximum possible time as upper bound
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            right = max(right, calculateTime(unstoppables[i], spells[j], p));
        }
    }
    
    long long answer = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canFinishInTime(unstoppables, spells, p, mid, n)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
