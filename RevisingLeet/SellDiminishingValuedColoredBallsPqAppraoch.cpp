class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const long long MOD = 1e9 + 7;
        const long long INV2 = 500000004LL;

        priority_queue<long long> pq;
        for (int x : inventory) pq.push(x);

        long long ans = 0;
        long long count = 1;

        while (orders > 0) {
            long long top = pq.top(); pq.pop();
            long long next = pq.empty() ? 0 : pq.top();

            long long rows = top - next;
            long long ballsAvailable = rows * count;

            if (ballsAvailable <= orders) {
                long long term = count % MOD 
                                 * ((top + next + 1) % MOD) % MOD 
                                 * (rows % MOD) % MOD 
                                 * INV2 % MOD;
                ans = (ans + term) % MOD;
                orders -= ballsAvailable;
                count++;
            } else {
                long long full     = orders / count;
                long long leftover = orders % count;

                long long hi = top, lo = top - full + 1;

                // Full rows term
                if (full > 0) {
                    long long term = count % MOD 
                                     * ((hi + lo) % MOD) % MOD 
                                     * (full % MOD) % MOD 
                                     * INV2 % MOD;
                    ans = (ans + term) % MOD;
                }

                // Leftover balls, each worth (top - full)
                ans = (ans + leftover % MOD * ((top - full) % MOD)) % MOD;
                orders = 0;
            }
        }

        return ans;
    }
};
