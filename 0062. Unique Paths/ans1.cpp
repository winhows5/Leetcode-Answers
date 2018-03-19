/* time cost: 2ms (100.00%) */
/* time complexity: O(m*n)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int uniquePaths(int m, int n) {
        int d[m][n];

        for (int row = 0; row < m; ++row)
            for (int col = 0; col < n; ++col) {
                if (row == 0 || col == 0) d[row][col] = 1;
                else d[row][col] = d[row-1][col] + d[row][col-1];
            }
        return d[m - 1][n - 1];
    }
};
