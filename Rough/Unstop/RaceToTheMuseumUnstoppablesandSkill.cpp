#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_possible(int n, int m, int p, const vector<int>& unstoppables, 
                const vector<int>& spells, int time) {
    int i = 0, j = 0;  // Pointers for unstoppables and spells
    
    while (i < n && j < m) {
        if (abs(unstoppables[i] - spells[j]) + abs(spells[j] - p) <= time) {
            i++;  // Assign this spell to this unstoppable
        }
        j++;  // Move to the next spell
    }
    
    return i == n;  // All unstoppables must be matched
}

int min_delivery_time(int n, int m, int p, vector<int>& unstoppables, vector<int>& spells) {
    sort(unstoppables.begin(), unstoppables.end());
    sort(spells.begin(), spells.end());
    
    // Binary search for minimum maximum time
    int left = 0;
    int right = max({*max_element(unstoppables.begin(), unstoppables.end()),
                     *max_element(spells.begin(), spells.end()), 
                     p}) * 2;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (is_possible(n, m, p, unstoppables, spells, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, p;
    cin >> n >> m >> p;
    
    vector<int> unstoppables(n);
    for (int i = 0; i < n; i++) {
        cin >> unstoppables[i];
    }
    
    vector<int> spells(m);
    for (int i = 0; i < m; i++) {
        cin >> spells[i];
    }
    
    int result = min_delivery_time(n, m, p, unstoppables, spells);
    cout << result << endl;
    
    return 0;
}
