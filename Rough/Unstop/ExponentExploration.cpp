#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> validPairs;
    
    // Special case for N = 1
    if (N == 1) {
        // For N = 1, we have infinite solutions: 1^Y = 1 for any Y
        // But typically we only count 1^1 = 1
        validPairs.push_back({1, 1});
    } else {
        // Check for Y = 1 (X = N)
        validPairs.push_back({N, 1});
        
        // Check for Y >= 2
        for (int X = 2; X * X <= N; X++) {
            long long currentPower = (long long)X * X; // Start with X^2
            int Y = 2;
            
            while (currentPower <= N) {
                if (currentPower == N) {
                    validPairs.push_back({X, Y});
                }
                
                // Check for overflow before next multiplication
                if (currentPower > N / X) break;
                
                currentPower *= X;
                Y++;
                
                // Safety check to prevent infinite loops
                if (Y > 30) break;
            }
        }
    }
    
    // Sort pairs by X value
    sort(validPairs.begin(), validPairs.end());
    
    // Output results
    cout << validPairs.size() << endl;
    for (const auto& pair : validPairs) {
        cout << pair.first << " " << pair.second << endl;
    }
    
    return 0;
}
