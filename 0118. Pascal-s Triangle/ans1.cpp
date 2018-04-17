/* time cost: 3ms (96.52%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; ++i) {
            vector<int> tmp(i, 1);
            for (int j = 1; j < i-1; ++j) 
                tmp[j] = ans[i-2][j] + ans[i-2][j-1];
            ans.push_back(tmp);
        }
        return ans;
    }
};
