/* time cost: 3ms (98.82%) */
/* time complexity: O(mn)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int l = strs[0].size();
        if(!l) return "";
        bool sgn = false;
        int j;
        for (j = 0; j < l; ++j) {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][j] != c) {
                    sgn = true;
                    break;
                }
            }
            if(sgn) break;
        }
        return strs[0].substr(0, j);
    }
};
