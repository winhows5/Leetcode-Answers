/* backtrack */
/* time cost: 4ms (99.89%) */
/* time complexity: O(n^2) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> Queens(n, string(n, '.'));
        vector<int> flag(5*n - 2, 1);
        solution(ans, Queens, flag, 0, n);
        return ans;
    }

    void solution(vector<vector<string>> &ans, vector<string> &Queens, 
                  vector<int> &flag, int row, int n) {
        if (row == n) {
            ans.push_back(Queens);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (flag[col] && flag[n + row + col] && flag[4*n - 2 - row + col]) {
                flag[col] = flag[n + row + col] = flag[4*n - 2 - row + col] = 0;
                Queens[row][col] = 'Q';
                solution(ans, Queens, flag, row + 1, n);
                flag[col] = flag[n + row + col] = flag[4*n - 2 - row + col] = 1;
                Queens[row][col] = '.';
            }
        }
    }
};
