/* time cost: 10ms (100.00%) */
/* time complexity: O(n)     */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int candy(vector<int>& ratings) {
        int nums = ratings.size();
        if (nums < 2) return nums;
        vector<int> candies(nums, 0);
        candies[0] = 1;
        for (int i = 1; i < nums; ++i) {
            candies[i] = ratings[i] > ratings[i-1] ? candies[i-1]+1 : 1;
        }
        int ans = candies[nums-1];
        for (int i = nums-2; i >= 0; --i) {
            candies[i] = ratings[i] > ratings[i+1] ? max(candies[i], candies[i+1]+1) : candies[i];
            ans += candies[i];
        }
        return ans;
    }
};
