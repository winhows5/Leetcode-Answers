static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:

    int numTrees(int n) {
        if (n == 0) return 0;
        int dp[n]{};
        dp[0] = 1;
        for (int i = 1; i < n; ++i) 
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) dp[i] += dp[i-1];
                else dp[i] += dp[j-1] * dp[i-j-1];
            }
        return dp[n-1];
    }
};
