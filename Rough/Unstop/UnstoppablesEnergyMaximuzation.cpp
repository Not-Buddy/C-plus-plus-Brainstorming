#include <iostream>
#include <algorithm>
using namespace std;

int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int P, Q;
    cin >> P >> Q;
    
    long long maxEnergy = 0;
    
    for (int i = P; i <= Q; i++) {
        int reversed = reverseNumber(i);
        maxEnergy += max(i, reversed);
    }
    
    cout << maxEnergy << endl;
    
    return 0;
}
