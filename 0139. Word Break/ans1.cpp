/* time cost: 4ms (99.79%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return true;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int lgh = s.size();
        vector<bool> dp(lgh, false);
        dp[0] = true;
        for (int i = 1; i <= lgh; ++i) 
            for (int j = i-1; j >= 0; --j) {
                if (dp[j])
                    if (dict.find(s.substr(j, i-j)) != dict.end()) {
                        dp[i] = 1;
                        break;
                    }
            }
        return dp[lgh];
    }
};
