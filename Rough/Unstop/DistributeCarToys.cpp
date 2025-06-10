#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int K, S;
    cin >> K >> S;
    
    int count = 0;
    for (int c1 = 0; c1 <= K; c1++) {
        for (int c2 = 0; c2 <= K; c2++) {
            int c3 = S - c1 - c2;
            if (c3 >= 0 && c3 <= K) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
