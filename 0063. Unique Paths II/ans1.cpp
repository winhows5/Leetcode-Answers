/* time cost: 3ms (100.00%) */
/* time complexity: O(m*n)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int d[m][n];
        for (int row = 0; row < m; ++row)
            for (int col = 0; col < n; ++col) {
                if (obstacleGrid[row][col] == 1) d[row][col] = 0;
                else if (row == 0 && col == 0) d[row][col] = 1;
                else if (row == 0) d[row][col] = d[row][col-1];
                else if (col == 0) d[row][col] = d[row-1][col];
                else d[row][col] = d[row-1][col] + d[row][col-1];
            }
        return d[m-1][n-1];
    }
};
