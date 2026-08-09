class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        std::queue<std::pair<int,int>> zeros{};
        for(int i{0};i<mat.size();i++)
        {
            for(int j{0};j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    zeros.push({i,j});
                }
            }
        }

        std::vector<std::pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!zeros.empty())
        {
            auto [r,c] = zeros.front();
            zeros.pop();

            for(const auto &d:dirs)
            {
                int nr = r + d.first;
                int nc = c + d.second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc]==-1){
                    dist[nr][nc] = dist[r][c] + 1;
                    zeros.push({nr,nc});
                }
            }
        }
        return dist;

    }
};
