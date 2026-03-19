#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> L(n + 1);
    for (int i = 1; i <= n; i++) cin >> L[i];

    int minEven = INT_MAX;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (L[i] == L[j]) continue;         // forbidden
            
            int cost = abs(L[i] - L[j]);
            
            if (cost % 2 == 0) {                // even cost
                minEven = min(minEven, cost);
            }
        }
    }

    if (minEven == INT_MAX) cout << -1 << endl;
    else cout << minEven << endl;

    return 0;
}
