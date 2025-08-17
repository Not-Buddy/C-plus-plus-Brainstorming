#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        std::queue<std::pair<int, int>> rotten_q;
        int fresh_count = 0;

        // 1. Initialize the queue with all rotten oranges and count fresh oranges.
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    rotten_q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh_count++;
                }
            }
        }

        // Edge case: No fresh oranges to begin with.
        if (fresh_count == 0) {
            return 0;
        }

        int minutes = 0;
        // Directions for 4-directional movement: right, left, down, up.
        std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // 2. Start the BFS process.
        // The loop continues as long as there are rotten oranges to spread from
        // and fresh oranges that could potentially be rotted.
        while (!rotten_q.empty() && fresh_count > 0) {
            // Process all oranges that were rotten at the beginning of this minute.
            int level_size = rotten_q.size();
            
            for (int i = 0; i < level_size; ++i) {
                std::pair<int, int> current_orange = rotten_q.front();
                rotten_q.pop();
                int r = current_orange.first;
                int c = current_orange.second;

                // Check all 4 neighbors.
                for (const auto& dir : directions) {
                    int nr = r + dir.first;  // neighbor row
                    int nc = c + dir.second; // neighbor col

                    // Check if the neighbor is within bounds and is a fresh orange.
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // It becomes rotten.
                        fresh_count--;    // Decrement the count of fresh oranges.
                        rotten_q.push({nr, nc}); // Add the newly rotten orange to the queue.
                    }
                }
            }
             // A full level (one minute) has passed.
            minutes++;
        }

        // 3. Check the result.
        // If fresh_count is 0, all oranges are rotten. Otherwise, it's impossible.
        return fresh_count == 0 ? minutes : -1;
    }
};

// Example usage
int main() {
    Solution sol;
    
    std::vector<std::vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
    std::cout << "Example 1 Output: " << sol.orangesRotting(grid1) << std::endl; // Expected: 4

    std::vector<std::vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    std::cout << "Example 2 Output: " << sol.orangesRotting(grid2) << std::endl; // Expected: -1

    std::vector<std::vector<int>> grid3 = {{0,2}};
    std::cout << "Example 3 Output: " << sol.orangesRotting(grid3) << std::endl; // Expected: 0

    return 0;
}

