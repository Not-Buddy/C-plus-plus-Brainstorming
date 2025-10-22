class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        auto it = upper_bound(matrix.begin(), matrix.end(), target,
        [] (int val, const vector<int>&row){ return val<row.front();});
        if(it == matrix.begin()) return false;
        const auto& row = *prev(it);

        return binary_search(row.begin(), row.end(), target);

    }
};
