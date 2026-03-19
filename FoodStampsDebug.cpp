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

    priority_queue<pair<long long, int>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(make_pair(v[i], i));
    }

    vector<vector<long long>> taken(n);

    long long ans = 0;

    while (m-- && !pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();

        long long taste = top.first;
        int idx = top.second;

        if (taste <= 0) break;

        ans += taste;
        taken[idx].push_back(taste);

        long long nextTaste = taste - d[idx];
        if (nextTaste > 0) {
            pq.push(make_pair(nextTaste, idx));
        }
    }

    // Print in required format
    for (int i = 0; i < n; i++) {
        if (taken[i].empty()) continue;

        cout << "type " << i + 1 << ": ";

        if (taken[i].size() == 1) {
            cout << taken[i][0] << "\n";
        } else {
            cout << taken[i][0] << " + (" << taken[i][0]
                 << " - " << d[i] << ") * "
                 << (taken[i].size() - 1)
                 << " = ";

            long long sum = 0;
            for (int j = 0; j < taken[i].size(); j++) {
                sum += taken[i][j];
            }
            cout << sum << "\n";
        }
    }

    cout << "answer: " << ans << "\n";

    return 0;
}
