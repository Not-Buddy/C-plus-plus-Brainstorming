using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
	vector<string> board (n,string(n,'.'));

	//Lambda function for validation
	auto isValid  = [] (const vector<string> &board, int row, int col) -> bool
	{
		int n = board.size();
		for(int i = 0; i<row;i++)
			if(board[i][col]=='Q') return false;
		for(int i = row -1 , j = col -1; i>= 0 && j>=0 ; i--, j--)
			if(board[i][j]=='Q') return false;
		for(int i = row - 1 , j = col + 1 ; i>=0&& j<=n;i--,j++)
			if(board[i][j]=='Q') return false;

		return true;		
	};
	//Recursive lambda function without function<> instead using a auto &self
    auto solve = [&](auto &self, vector<string> &board, int row, vector<vector<string>> &result) -> void

	{
		if(board.size()==row){
			result.push_back(board);
			return;
		}

		for(int col = 0;col<board.size();col++){
			if(isValid(board,row,col)){
				board[row][col] = 'Q';
				self(self,board, row+1,result);
				board[row][col] = '.';
			}
		}
	};

	solve(solve, board, 0, result);
	return result;
    }
};
