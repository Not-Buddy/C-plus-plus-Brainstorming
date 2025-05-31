#include <iostream>
#include <vector>
using namespace std;
#include <deque>
#include <climits>

int min_mana(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Directions: right(a), left(b), down(c), up(d)
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    char dir[4] = {'a', 'b', 'c', 'd'};

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    deque<pair<int, int>> dq;
    dist[0][0] = 0;
    dq.push_front({0, 0});

    while (!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int cost = (grid[x][y] == dir[k]) ? 0 : 1;
                if (dist[nx][ny] > dist[x][y] + cost) {
                    dist[nx][ny] = dist[x][y] + cost;
                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
    }
    return dist[m-1][n-1];
}


int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    int result = min_mana(grid);
    cout << result << endl;
    
    return 0;
}
