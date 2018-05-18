/* time cost: 8ms (99.63%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int& c : nums)
            ans ^= c;
        return ans;
    }
};
