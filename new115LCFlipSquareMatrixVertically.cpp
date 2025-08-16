class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j{y};j<y+k;j++)
        {
            std::vector<int> replace{};
            for(int i{x};i<k+x;i++)
            {
                    replace.push_back(grid[i][j]);
            }
            reverse(replace.begin(),replace.end());

            int ptr=0;
            for(int i{x};i<k+x;i++)
            {
                grid[i][j]=replace[ptr];
                      ptr++;  
            }
        }

        return grid;
    }
};
