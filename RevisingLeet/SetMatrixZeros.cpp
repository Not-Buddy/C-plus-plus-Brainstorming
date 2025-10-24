class Solution {
public:
    void RowZero(vector<vector<int>> &matrix, int i,int j)
    {
        for(int k{0};k<matrix[i].size();k++)
        {
            matrix[i][k]=0;
        }
    }
    void ColumnZero(vector<vector<int>> &matrix, int i,int j)
    {
        {
        for(int k{0};k<matrix.size();k++)
        {
            matrix[k][j]=0;
        }
    }
        
    }
    void setZeroes(vector<vector<int>>& matrix) {
        std::vector<std::pair<int,int>>  IndicesZeros{};
        for(int i{0};i<matrix.size();i++)
        {
            for(int j{0};j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                    IndicesZeros.push_back(make_pair(i,j));
            }
        }
        for(const auto pair:IndicesZeros)
        { 
            RowZero(matrix,pair.first,pair.second);
            ColumnZero(matrix,pair.first, pair.second);
        }
    }
};
