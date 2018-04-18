/* time cost: 5ms (99.86%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0 || triangle[0].size() == 0) return 0;
        vector<int> paths(n, triangle[0][0]);
        int res = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            int pre = paths[0];
            int tmp;
            for (int j = 0; j <= i; ++j) {
                tmp = paths[j];
                if (j == 0) {
                    paths[j] = triangle[i][j] + pre;
                    res = paths[j];
                }
                else if (j == i) {
                    paths[j] = triangle[i][j] + pre;
                    res = min(res, paths[j]);
                }
                else {
                    paths[j] = triangle[i][j] + min(pre, paths[j]);
                    res = min(res, paths[j]);
                }
                pre = tmp;
            }
        }
        return res;
    }
};
