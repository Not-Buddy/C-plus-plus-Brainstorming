#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long int

int subset_xor_sum(const std::vector<int> &arr)
{
    /* Write your logic here */
    // return 0;  // Placeholder return
    ll n = arr.size();
    ll sum = 0, xr = 0;
    for (int i = 0; i < 31; ++i)
    {
        xr = 0;
        for (auto pr : arr)
        {
            if (pr & (1 << i))
                xr++;
        }
        sum += (1 << i) * (1 << (xr - 1)) * (1 << (n - xr));
    }
    return sum;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    int result = subset_xor_sum(arr);
    std::cout << result << std::endl;
    return 0;
}