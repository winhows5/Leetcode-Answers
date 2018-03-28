/* time cost: 6ms (52.21%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void iteration(vector<int> &ans, int n) {
        if (n == 1) {
            ans = vector<int>{0, 1};
            return;
        }   
        iteration(ans, n-1);
        int lngth = ans.size() - 1;
        for (int i = lngth; i >= 0; --i) {
            ans.push_back(ans[i] + (1 << n-1));   
        }
    }
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int>{0};
        vector<int> ans;
        iteration(ans, n);
        return ans;
    }
};
