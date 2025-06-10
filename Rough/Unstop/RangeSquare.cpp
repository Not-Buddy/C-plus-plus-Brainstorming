#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N1, N2;
    cin >> N1 >> N2;
    
    int N;
    cin >> N;
    
    // Use set for O(log N) lookup
    set<int> values;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        values.insert(val);
    }
    
    // Check perfect squares for integers from N1 to N2
    for (int i = N1; i <= N2; i++) {
        int square = i * i;
        if (values.find(square) != values.end()) {
            cout << 1 << endl;
            return 0;
        }
    }
    
    cout << 0 << endl;
    return 0;
}
