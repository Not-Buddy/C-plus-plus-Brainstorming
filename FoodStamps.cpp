#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;

    vector<long long> v(n), d(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    // max heap to always pick best next taste
    priority_queue<pair<long long, int>> pq;

    for (int i = 0; i < n; i++) {
        pq.push({v[i], i});
    }

    long long ans = 0;

    while (m-- && !pq.empty()) {
        auto [taste, i] = pq.top();
        pq.pop();

        if (taste <= 0) break;

        ans += taste;

        long long nextTaste = taste - d[i];
        if (nextTaste > 0) {
            pq.push({nextTaste, i});
        }
    }

    cout << ans << "\n";
    return 0;
}
