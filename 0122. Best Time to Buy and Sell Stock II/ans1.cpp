/* time cost: 5ms (99.92%) */
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
        int pre_min = INT_MAX;
        for (int i = 1; i < prices.size(); ++i) {
            while (prices[i] > prices[i-1]) {
                pre_min = min(pre_min, prices[i-1]);
                ++i;
                if (i == prices.size()) {
                    ans += prices[i-1] - pre_min;
                    return ans;
                }
            }
            if (pre_min != INT_MAX) {
                ans += prices[i-1] - pre_min;
                pre_min = INT_MAX;
            }
            
        }
        return ans;
    }
};
