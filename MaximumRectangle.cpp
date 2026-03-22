#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	//Area = height[j] * (right[j] - left[j])
    int maximalRectangle(vector<vector<char>>& matrix) {
        
	    if(matrix.empty() || matrix[0].empty()) return 0;
	    
	    int rows = matrix.size();
	    int cols = matrix[0].size();

	    //dp vectors starting state
	    vector<int> height(cols, 0);
	    vector<int> left(cols, 0);
	    vector<int> right(cols,cols);

	    int max_area = 0;

	    for(int i{0};i<rows;i++)
	    {
		int cur_left = 0;
		int cur_right = cols;


		//get height and store it in height for each col
		for(int j{0};j<cols;j++)
		{
			if(matrix[i][j] == '1')
				height[j]++;
			else 
				height[j]=0;
		}

		//Update left vector
		
		for(int j{0}; j<cols; j++)
		{
			if(matrix[i][j]=='1')
				left[j] = max(left[j], cur_left);
			else 
			{
				left[j]=0;
				cur_left = j+1;
			}
		}

		//Update vector right

		for(int j{cols-1};j>=0;j--)
		{
			if(matrix[i][j] == '1')
				right[j] = min(right[j], cur_right);
			else
			{
				right[j]=cols;
				cur_right = j;
			}
		}

		for(int j{0};j<cols;j++)
			max_area = max(max_area, height[j] * (right[j]-left[j]));


	    }
	    return max_area;


    }
};
