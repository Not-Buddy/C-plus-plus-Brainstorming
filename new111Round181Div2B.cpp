#include <bits/stdc++.h>
using namespace std;
int main() 
{
    long long t;
    cin >> t;
    while (t--) 
    {
        long long a, b, k;
        cin >> a >> b >> k;
        long long hcf = __gcd(a, b);
        long long x = max((a + k - 1) / k, (b + k - 1) / k);
        cout << (hcf >= x ? 1 : 2) << '\n';
    }
    return 0;
}
