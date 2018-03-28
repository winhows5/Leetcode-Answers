/* time cost: 9ms (100.00%) */
/* time complexity: O(mn)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// Hard to solve concisely as that
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int left[n]{}, right[n], height[n]{};
        fill_n(right, n, n);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int left_t = 0, right_t = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                    left[j] = max(left_t, left[j]);
                }
                else {
                    height[j] = 0;
                    left[j] = 0;
                    left_t = j+1;
                }   
            }
            for (int j = n-1; j>= 0; --j) {
                if (matrix[i][j] == '1') right[j] = min(right[j], right_t);
                else {
                    right[j] = n;
                    right_t = j;
                }
            }
            for (int j = 0; j < n; ++j)
                ans = max(ans, height[j] * (right[j] - left[j]));
        }
        return ans;
    }
};
