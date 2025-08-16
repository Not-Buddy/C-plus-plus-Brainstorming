#include <bits/stdc++.h>
using namespace std;

// Count of numbers in [1..x] that are NOT divisible by any of {2,3,5,7},
// i.e., numbers coprime with 210.
unsigned long long count_good_upto(unsigned long long x) {
    static const int ps[4] = {2, 3, 5, 7};
    unsigned long long res = 0;
    // Enumerate all subsets of the 4 primes via bitmask [0..15]
    for (int mask = 0; mask < 16; ++mask) {
        unsigned long long m = 1;
        int bits = 0; // popcount(mask)
        for (int i = 0; i < 4; ++i) {
            if (mask & (1 << i)) {
                m *= ps[i];
                ++bits;
            }
        }
        // sg = (-1)^bits
        long long sg = (bits % 2 == 0 ? +1 : -1);
        res += sg * (x / m);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        unsigned long long l, r;
        cin >> l >> r;
        unsigned long long ans = count_good_upto(r) - count_good_upto(l - 1);
        cout << ans << '\n';
    }
    return 0;
}

