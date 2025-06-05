#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class EnemyExodus {
private:
    // Optimized ceiling division using bit manipulation for powers of 2
    inline long long ceilDiv(long long a, int b) {
        return (a + b - 1) / b;
    }
    
    // Fast octal conversion using bitwise operations
    string toOctalFast(int num) {
        if (num == 0) return "0";
        
        string result;
        result.reserve(12); // Pre-allocate for efficiency
        
        while (num > 0) {
            result += char('0' + (num & 7)); // num & 7 is equivalent to num % 8
            num >>= 3; // num >>= 3 is equivalent to num / 8
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    // Optimized check function with early termination
    bool canKillAll(int K, const vector<int>& groups, int M) {
        long long totalMinutes = 0;
        
        for (int enemies : groups) {
            totalMinutes += ceilDiv(enemies, K);
            // Early termination if we exceed the limit
            if (totalMinutes > M) return false;
        }
        
        return true;
    }

public:
    pair<int, string> solve(vector<int>& groups, int M) {
        int N = groups.size();
        
        // Early optimization: calculate sum once
        long long totalEnemies = accumulate(groups.begin(), groups.end(), 0LL);
        
        // Early termination: if total enemies <= M, answer is 1
        if (totalEnemies <= M) {
            return {1, "1"};
        }
        
        // Optimized bounds
        int maxEnemies = *max_element(groups.begin(), groups.end());
        
        // Better lower bound: theoretical minimum based on total enemies
        int low = max(1, (int)ceilDiv(totalEnemies, M));
        int high = maxEnemies;
        
        // Early check: if even with max kill rate we can't finish in time
        if (!canKillAll(high, groups, M)) {
            return {-1, "1"};
        }
        
        int minK = high;
        
        // Optimized binary search
        while (low < high) {
            int mid = low + (high - low) / 2; // Prevent overflow
            
            if (canKillAll(mid, groups, M)) {
                minK = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return {minK, toOctalFast(minK)};
    }
};

int main() {
    ios_base::sync_with_stdio(false); // Fast I/O
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> groups;
    groups.reserve(N); // Pre-allocate memory
    
    for (int i = 0; i < N; i++) {
        int enemies;
        cin >> enemies;
        groups.push_back(enemies);
    }
    
    int M;
    cin >> M;
    
    EnemyExodus solver;
    auto result = solver.solve(groups, M);
    
    if (result.first == -1) {
        cout << "1 1\n";
    } else {
        cout << result.first << " " << result.second << "\n";
    }
    
    return 0;
}
