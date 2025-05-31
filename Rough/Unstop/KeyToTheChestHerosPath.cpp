#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <bits/stdc++.h>
using namespace std;
void find_shortest_path(std::vector<std::vector<char>>& grid, int n, int m) {
    pair<int, int> hero, chest;
    std::vector<pair<int, int>> keys;
    std::vector<std::vector<int>> key_index(n, std::vector<int>(m, -1));

    // Identify positions of hero, chest, and keys
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'H') hero = {i, j};
            if (grid[i][j] == 'C') chest = {i, j};
            if (grid[i][j] == 'K') {
                key_index[i][j] = keys.size();
                keys.push_back({i, j});
            }
        }

    int num_keys = keys.size();
    int all_keys_mask = (1 << num_keys) - 1;

    // BFS: state = (x, y, keys_mask, steps)
    std::queue<std::tuple<int, int, int, int>> q;
    std::vector<std::vector<std::vector<bool>>> visited(n, std::vector<std::vector<bool>>(m, std::vector<bool>(1 << num_keys, false)));
    q.push(std::make_tuple(hero.first, hero.second, 0, 0));
    visited[hero.first][hero.second][0] = true;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        int x, y, mask, steps;
        std::tie(x, y, mask, steps) = q.front();
        q.pop();

        // If at chest and all keys collected
        if (x == chest.first && y == chest.second && mask == all_keys_mask) {
            std::cout << steps << std::endl;
            return;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            char cell = grid[nx][ny];
            if (cell == 'O') continue;
            if (cell == 'C' && mask != all_keys_mask) continue; // Can't enter chest before all keys

            int new_mask = mask;
            if (cell == 'K' && key_index[nx][ny] != -1)
                new_mask |= (1 << key_index[nx][ny]);

            if (!visited[nx][ny][new_mask]) {
                visited[nx][ny][new_mask] = true;
                q.push(std::make_tuple(nx, ny, new_mask, steps + 1));
            }
        }
    }

    std::cout << "Impossible" << std::endl;
}

      
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> grid(n, std::vector<char>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> grid[i][j];
        }
    }
    
    find_shortest_path(grid, n, m);
    
    return 0;
}

