/* time cost: 79ms (71.30%) */
/* time complexity: O(2^n)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ans_t(k, 0);
        int i = 0;
        while (i >= 0) {
            ++ans_t[i];
            if (ans_t[i] > n) --i;
            else if (i == k - 1) ans.push_back(ans_t);
            else {
                ++i;
                ans_t[i] = ans_t[i - 1];
            }
        }
        return ans;
    }
};
