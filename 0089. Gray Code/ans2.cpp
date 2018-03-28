/* time cost: 5ms (83.26%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int>{0};
        vector<int> ans{0};
        for (int i = 0; i < n; ++i)
            for (int j = ans.size()-1; j >= 0; --j) {
                ans.push_back(ans[j] | (1 << i));   
        }
        return ans;
    }
};
