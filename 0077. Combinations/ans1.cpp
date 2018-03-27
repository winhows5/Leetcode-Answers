/* time cost: 71ms (97.90%) */
/* time complexity: O(2^n)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void iteration(vector<vector<int>> &ans, vector<int> &ans_t, int begin, int num, int n, int k) {
        if (num == k) {
            ans.push_back(ans_t);
            return;
        }
        for (int i = begin; i <= n - (k - num - 1); ++i) {
            ans_t[num] = i;
            iteration(ans, ans_t, i + 1, num + 1, n, k);
            ans_t[num] = 0;
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ans_t(k, 0);
        iteration(ans, ans_t, 1, 0, n, k);
        return ans;
    }
};
