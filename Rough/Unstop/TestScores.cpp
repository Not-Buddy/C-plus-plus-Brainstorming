#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    // Sort scores in ascending order for binary search
    sort(scores.begin(), scores.end());
    
    // Process each query
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        
        // Find first position where score >= x using lower_bound
        auto it = lower_bound(scores.begin(), scores.end(), x);
        
        // Number of students with score >= x
        int count = scores.end() - it;
        
        cout << count << "\n";
    }
    
    return 0;
}
