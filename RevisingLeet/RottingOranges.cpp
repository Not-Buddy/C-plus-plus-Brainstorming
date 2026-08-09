class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
	
	std::queue<std::pair<int,int>> rotten_orange{};
        int fresh_oranges{};
        for(int i{0};i<grid.size();i++)
        {
          for(int j{0};j<grid[i].size();j++)
	  {
		  if(grid[i][j] == 1)
			  fresh_oranges++;
		  else if(grid[i][j] == 2)
		  	rotten_orange.push({i,j});
	  }       
	}
	

	if(fresh_oranges == 0) return 0;
	if(rotten_orange.size()==0) return -1;
	
	std::vector<std::pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
	int mins = 0;

	while(!rotten_orange.empty()){
		
		int cur_size = rotten_orange.size();
		bool rot_this_min = false;

		for(int i{0};i<cur_size;i++)
		{
			auto [r,c] = rotten_orange.front();
			rotten_orange.pop();
			
			for(auto d:dir)
			{
				int nr = d.first + r;
				int nc = d.second + c;

				if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1)
				{
					grid[nr][nc] = 2;
					fresh_oranges--;
					rotten_orange.push({nr,nc});
					rot_this_min = true;
				}
			}
		}

		if(rot_this_min) mins++;

	}

	
      return fresh_oranges == 0 ? mins : -1;  

    }
};
