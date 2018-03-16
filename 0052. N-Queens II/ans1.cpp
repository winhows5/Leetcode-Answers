/* time cost: 3ms (96.94%) */
/* time complexity: O(n^2) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> flag(5*n - 2, 1);
        solution(ans, flag, 0, n);
        return ans;
    }
    
    void solution(int &ans, vector<int> &flag, int row, int n) {
        if (row == n) {
            ++ans;
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (flag[col] && flag[n + row + col] && flag[4*n-2 - row + col]) {
                flag[col] = flag[n + row + col] = flag[4*n-2 - row + col] = 0;
                solution(ans, flag, row+1, n);
                flag[col] = flag[n + row + col] = flag[4*n-2 - row + col] = 1;
            }
        }
    }
};
