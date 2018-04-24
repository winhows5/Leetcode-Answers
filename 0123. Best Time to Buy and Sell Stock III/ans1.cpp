/* time cost: 6ms (100.00%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int t = 2;
        vector<vector<int>> dp(t+1, vector<int>(prices.size(), 0));
        for (int j = 1; j <= t; ++j) {
            // dp[j][i] = max(dp[j][i-1], dp[j-1][it] + prices[i] - prices[it])
            // it in range [0, i-1]
            int pre_max = dp[j-1][0] - prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                dp[j][i] = max(dp[j][i-1], pre_max + prices[i]);
                pre_max = max(pre_max, dp[j-1][i] - prices[i]);
            }
        }
        return max(dp[t-1][prices.size()-1], dp[t][prices.size()-1]);
    }
};
