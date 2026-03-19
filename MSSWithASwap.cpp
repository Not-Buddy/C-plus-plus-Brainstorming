#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = *max_element(a.begin(), a.end());

    for(int l = 0; l < n; l++)
    {
        for(int r = l; r < n; r++)
        {
            // Collect ALL inside elements, sorted ascending (worst first)
            vector<int> inside;
            int windowSum = 0;
            for(int i = l; i <= r; i++)
            {
                windowSum += a[i];
                inside.push_back(a[i]);
            }
            sort(inside.begin(), inside.end());

            vector<int> outside;
            for(int i = 0; i < n; i++)
            {
                if(i < l || i > r)
                    outside.push_back(a[i]);
            }
            sort(outside.rbegin(), outside.rend());

            int swaps = 0;
            int i = 0, j = 0;
            while(swaps < k && i < (int)inside.size() && j < (int)outside.size())
            {
                if(outside[j] > inside[i])
                {
                    windowSum += outside[j] - inside[i];
                    i++; j++; swaps++;
                }
                else break;
            }

            ans = max(ans, windowSum);
        }
    }

    cout << ans << endl;
    return 0;
}
