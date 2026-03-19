class Solution {
public:
    int maxProfit(vector<int>& a, int orders) {
        const int MOD = 1e9 + 7;
        sort(a.rbegin(), a.rend());

        long long ans = 0;
        int n = a.size();

        for (int i = 0; orders > 0; i++) {
            long long curr = a[i];
            long long next = (i + 1 < n ? a[i + 1] : 0);
            long long count = i + 1;

            long long take = min((long long)orders, count * (curr - next));
            long long k = take / count, r = take % count;

            ans = (ans + count * (curr + curr - k + 1) * k / 2) % MOD;
            ans = (ans + r * (curr - k)) % MOD;

            orders -= take;
        }

        return (int)ans;
    }
};
