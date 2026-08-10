class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
 	
	int n = grid.size();
	int m = grid[0].size();

	std::queue<std::pair<int,int>> q{};
	if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
		return -1;

	q.push({0,0});
	grid[0][0] = 1;

	std::vector<std::pair<int,int>> dirs = {{1,-1},{1,0},{0,1},{1,1},
						{-1,0},{0,-1},{-1,-1},{-1,1}};

	while(!q.empty())
	{
		auto [r,c] = q.front();
		q.pop();

		if(r==n-1 && c == m-1)
			return grid[n-1][m-1];
		
		for(const auto &d:dirs)
		{
			int nr = r + d.first;
			int nc = c + d.second;

			if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 0)
			{
				grid[nr][nc] = grid[r][c] + 1;
				q.push({nr,nc});
			}
		}
	}
	
	return -1;

    }
};
