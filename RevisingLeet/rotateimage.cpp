class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Correctly initialize an n x n matrix
    vector<vector<int>> rotated(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // The element at original row i, col j
            // moves to new row j, col (n-1-i)
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }

    // Assign the newly rotated matrix back to the original
    matrix = rotated;
}
};