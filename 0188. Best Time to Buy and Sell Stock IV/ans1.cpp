/* time cost: 8ms (74.23%) */
/* time complexity: O(n) */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        if (k+n<3) return res;
        if (2*k >= n) {        // the maxium case
            for (int i=0; i<n; ++i) {
                int min = prices[i];
                while (i+1<n && prices[i+1] >= prices[i] ) {
                    ++i;
                }
                res += prices[i] - min;
            }  
        } else {
            int dp[k+1][n];        // dp[k][n] = max(dp[k][n-1], dp[k-1][i]+tmp)
            for (int j=0;j<n;++j) dp[0][j] = 0;
            for (int i=1;i<=k;++i) {
                dp[i][0] = 0;
                int tmpMax = dp[i-1][0] - prices[0];
                for (int j=1;j<n;++j) {
                    dp[i][j] = max(dp[i][j-1], prices[j]+tmpMax);
                    tmpMax = max(tmpMax, dp[i-1][j-1]-prices[j]);
                }
            }
            res = dp[k][n-1];
        }
        
        
        return res;
        
    }
};