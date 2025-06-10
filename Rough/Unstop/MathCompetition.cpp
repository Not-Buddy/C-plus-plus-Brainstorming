#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> s(3);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }
    
    int total_sum = accumulate(s.begin(), s.end(), 0);
    
    if (total_sum % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    int max_draws = (total_sum - max(0, s[2] - s[0] - s[1])) / 2;
    cout << max_draws << endl;
    
    return 0;
}
