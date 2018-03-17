/* time cost: 8ms (99.76%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int longth = nums.size();
        int dp[longth];        // dp[] means the max subarray ended with nums[i]
        dp[0] = nums[0];
        int max_array = dp[0];
        for (int i = 1; i < longth; ++i) {
            dp[i] = max(nums[i] + dp[i-1], nums[i]);
            max_array = max(max_array, dp[i]);
        }
        return max_array;
    }
};
