/* time cost: 3ms (99.93%) */
/* time complexity: O(m*n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int d[m][n];
        for (int row = 0; row < m; ++row)
            for (int col = 0; col < n; ++col) {
                if (row == 0 && col == 0) d[row][col] = grid[row][col];
                else if (row == 0) d[row][col] = grid[row][col] + d[row][col-1];
                else if (col == 0) d[row][col] = grid[row][col] + d[row-1][col];
                else d[row][col] = grid[row][col] + min(d[row-1][col], d[row][col-1]);
            }
        
        return d[m-1][n-1];
    }
};
