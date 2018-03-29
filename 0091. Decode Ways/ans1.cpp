/* time cost: 3ms (97.89%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int valid(char a, char b) {
        if (a - '0' > 2 || a == '0') 
            if (b == '0') return -1;
            else return 0;
        else if (a - '0' == 2 && b - '0' > 6) return 0;
        else return 1;
    }
    int numDecodings(string s) {
        int lng = s.size();
        if (lng == 0 || s[0] == '0') return 0;
        int dp[lng]{};
        dp[lng-1] = s[lng-1] == '0' ? 0 : 1;
        if (lng > 1)
            if (valid(s[lng-2], s[lng-1]) == -1) return 0;
            else if (valid(s[lng-2], s[lng-1]) == 1) dp[lng-2] = dp[lng-1]+1;
            else dp[lng-2] = dp[lng-1];
        
        for (int i = lng-3; i >= 0; --i) {
            if (valid(s[i], s[i+1]) == -1) return 0;
            else if (valid(s[i], s[i+1]) == 1 && s[i+1] != '0' && s[i+2] != '0')
                dp[i] = dp[i+1] + dp[i+2];
            else
                dp[i] = dp[i+1];
        }
        return dp[0];
    }
};
