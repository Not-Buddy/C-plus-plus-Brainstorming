#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    long long currentAltitude = 0;
    long long maxAltitude = 0;
    
    for (int i = 0; i < n; i++) {
        long long change;
        cin >> change;
        
        // Apply the altitude change
        currentAltitude += change;
        
        // If altitude becomes negative, reset to 0 (hover mode)
        if (currentAltitude < 0) {
            currentAltitude = 0;
        }
        
        // Update maximum altitude
        maxAltitude = max(maxAltitude, currentAltitude);
    }
    
    cout << maxAltitude << endl;
    
    return 0;
}
