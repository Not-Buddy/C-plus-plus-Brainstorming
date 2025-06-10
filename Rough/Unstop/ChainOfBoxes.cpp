#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> chain(n);
    for (int i = 0; i < n; i++) {
        cin >> chain[i];
    }
    
    // Print in reverse order
    for (int i = n - 1; i >= 0; i--) {
        cout << chain[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
    
    return 0;
}
