#include <iostream>
#include <algorithm>
using namespace std;

int solve(int s1, int s2, int s3) {
    // Handle all zero scores
    if (s1 == 0 && s2 == 0 && s3 == 0) {
        return -1;
    }
    
    // Check if total score is even (necessary condition)
    long long total = (long long)s1 + s2 + s3;
    if (total % 2 != 0) {
        return -1;
    }
    
    // Sort scores to handle edge cases systematically
    int scores[3] = {s1, s2, s3};
    sort(scores, scores + 3);
    int a = scores[0], b = scores[1], c = scores[2];
    
    // Check triangle inequalities more carefully
    // For the optimal solution to exist, we need:
    // a + b >= c (most restrictive since c is largest)
    if (a + b < c) {
        return -1;
    }
    
    // Additional validation: check if we can construct valid b12, b13, b23
    // b12 = (s1 + s2 - s3) / 2
    // b13 = (s1 + s3 - s2) / 2  
    // b23 = (s2 + s3 - s1) / 2
    // All must be non-negative
    
    if ((s1 + s2 - s3) < 0 || (s1 + s3 - s2) < 0 || (s2 + s3 - s1) < 0) {
        return -1;
    }
    
    // Check if the differences are even (they should be if total is even)
    if ((s1 + s2 - s3) % 2 != 0 || (s1 + s3 - s2) % 2 != 0 || (s2 + s3 - s1) % 2 != 0) {
        return -1;
    }
    
    // Return maximum "both correct" problems
    return (int)(total / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    cout << solve(s1, s2, s3) << endl;
    
    return 0;
}
