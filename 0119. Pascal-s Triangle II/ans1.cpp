/* time cost: 3ms (80.79%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);
        for (int i = 2; i <= rowIndex+1; ++i) {
            int pre = ans[0];
            for (int j = 1; j < i-1; ++j) {
                int tmp = ans[j];
                ans[j] = ans[j] + pre;
                pre = tmp;
            }
        }
        return ans;
    }
};
