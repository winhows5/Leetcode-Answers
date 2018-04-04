/* time cost: 3ms (97.40%) */
/* time complexity: O(nm)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int lngth1 = s1.size(), lngth2 = s2.size(), lngth3 = s3.size();
        if (lngth1 + lngth2 != lngth3) return false;
        bool dp[lngth3+1][lngth1+1]{};
        dp[0][0] = true;
        for (int i = 1; i <= lngth3; ++i)
            for (int j = 0; j <= lngth1; ++j) {
                if (j > i) continue;
                else if (j == i) dp[i][j] = dp[i-1][j-1] && s3[i-1] == s1[j-1];
                else if (j == 0) dp[i][j] = dp[i-1][j] && s3[i-1] == s2[i-1];
                else dp[i][j] = (dp[i-1][j-1] && s3[i-1] == s1[j-1]) ||
                                (dp[i-1][j] && s3[i-1] == s2[i-j-1]);
                
            }
        return dp[lngth3][lngth1];
    }
};
