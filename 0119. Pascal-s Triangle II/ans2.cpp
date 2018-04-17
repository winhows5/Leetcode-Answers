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
        vector<int> pre;
        for (int i = 1; i <= rowIndex+1; ++i) {
            vector<int> cur(i, 1);
            for (int j = 1; j < i-1; ++j)
                cur[j] = pre[j] + pre[j-1];
            pre = cur;
        }
        return pre;
    }
};
