/* time cost: 10ms (99.45%) */
/* time complexity: O(mn)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        vector<int> dp(sz1+1, 0);
        
        int pre;
        for (int i = 0; i <= sz1; ++i) dp[i] = i;
        for (int j = 1; j <= sz2; ++j) {
            pre = dp[0];
            dp[0] = j;
            for (int i = 1; i <= sz1; ++i) {
                int temp = dp[i];
                if (word1[i-1] == word2[j-1]) dp[i] = pre;
                else dp[i] = min(pre, min(dp[i], dp[i-1])) + 1;
                pre = temp;
            }
        }
        return dp[sz1];
    }
};
