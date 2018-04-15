/* time cost: 4ms (100.00%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int numDistinct(string s, string t) {
        int ssize = s.size(), tsize = t.size();
//         int dp[ssize+1][tsize+1]{};
//         for (int i = 0; i <= ssize; ++i) dp[i][0] = 1;
//         for (int i = 1; i <= ssize; ++i)
//             for (int j = 1; j <= tsize && j <= i; ++j) {
//                 dp[i][j] = s[i-1] == t[j-1] ? dp[i-1][j] + dp[i-1][j-1] : dp[i-1][j]; 
//             }
        int dp[tsize+1]{1};
        for (int i = 1; i <= ssize; ++i) {
            int pre = dp[0];
            for (int j = 1; j <= tsize && j <= i; ++j) {
                int tmp = dp[j];
                dp[j] = s[i-1] == t[j-1] ? dp[j] + pre : dp[j]; 
                pre = tmp;
            }
        }  
        return dp[tsize];
    }
};
