/* time cost: 6ms (99.61%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int low = INT_MAX;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] <= prices[i-1]) continue;
            else {
                low = min(low, prices[i-1]);
                ans = max(ans, prices[i] - low);
            }
        }
        return ans;
    }
};
