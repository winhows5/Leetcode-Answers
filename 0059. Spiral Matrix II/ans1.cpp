/* time cost: 4ms (100.00%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int circle = n / 2;
        int num = 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int c = 0; c <= circle; ++c) {
            for (int col = c; col < n - c; ++col) {
                ans[c][col] = num;
                ++num;
            }
            if (c == n - c - 1) break;
            
            for (int row = c + 1; row <= n - c - 2; ++row) {
                ans[row][n-1-c] = num;
                ++num;
            }
            
            for (int col = n - c - 1; col >= c; --col) {
                ans[n-1-c][col] = num;
                ++num;
            }
            
            for (int row = n - 2 - c; row >= c + 1; --row) {
                ans[row][c] = num;
                ++num;
            }
        }
        return ans;
    }
};
