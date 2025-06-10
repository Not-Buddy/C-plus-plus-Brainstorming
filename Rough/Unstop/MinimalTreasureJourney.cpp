#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min_treasure(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int j = 0; j < n; ++j)
    {
        dp[0][j] = grid[0][j];
    }

    for (int i = 1; i < n; ++i)
    {
        int min_val = INT_MAX, second_min_val = INT_MAX;
        int min_index = -1;

        for (int j = 0; j < n; ++j)
        {
            if (dp[i - 1][j] < min_val)
            {
                second_min_val = min_val;
                min_val = dp[i - 1][j];
                min_index = j;
            }
            else if (dp[i - 1][j] < second_min_val)
            {
                second_min_val = dp[i - 1][j];
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (j != min_index)
            {
                dp[i][j] = min(dp[i][j], min_val + grid[i][j]);
            }
            else
            {
                dp[i][j] = min(dp[i][j], second_min_val + grid[i][j]);
            }
        }
    }

    int result = INT_MAX;
    for (int j = 0; j < n; ++j)
    {
        result = min(result, dp[n - 1][j]);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int result = min_treasure(grid);
    cout << result << endl;
    return 0;
}