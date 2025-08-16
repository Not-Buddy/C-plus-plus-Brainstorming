#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool HasRotten(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2) return true;
        return false;
    }

    bool NotAllRotten(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) return true;
        return false;
    }

    // Process one minute: from all current rotten positions, rot adjacent fresh ones.
    // Returns true if at least one fresh orange became rotten in this minute.
    bool passAMinute(vector<vector<int>>& grid, const vector<pair<int,int>>& rotten) {
        int m = grid.size(), n = grid[0].size();
        bool changed = false;
        
        // Correct directions array
        static const int dirs[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // Collect to-rot first to simulate simultaneous rotting
        vector<pair<int,int>> toRot;
        toRot.reserve(rotten.size() * 4); // Fixed: removed backslash

        for (auto rc : rotten) {
            int r = rc.first, c = rc.second;
            for (int di = 0; di < 4; ++di) {
                int nr = r + dirs[di][0]; // Fixed: use dirs[di] for row offset
                int nc = c + dirs[di][1]; // Fixed: use dirs[di] for column offset
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] == 1) {
                    toRot.push_back({nr, nc}); // Fixed: removed backslash
                }
            }
        }

        for (auto rc : toRot) {
            int r = rc.first, c = rc.second;
            if (grid[r][c] == 1) {
                grid[r][c] = 2;
                changed = true;
            }
        }
        return changed;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        bool anyRotten = HasRotten(grid);
        bool anyFresh = NotAllRotten(grid);
        if (!anyRotten) return anyFresh ? -1 : 0;
        if (!anyFresh) return 0;

        int minutes = 0;

        while (true) {
            vector<pair<int,int>> rotten;
            rotten.reserve(m * n); // Fixed: removed backslash
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 2) rotten.push_back({i, j}); // Fixed: removed backslash
                }
            }

            bool changed = passAMinute(grid, rotten);
            if (!changed) break;
            ++minutes;

            if (!NotAllRotten(grid)) return minutes;
        }

        return NotAllRotten(grid) ? -1 : minutes;
    }
};

