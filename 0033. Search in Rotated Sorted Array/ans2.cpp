/* time cost: 4ms (99.31%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int search(vector<int>& nums, int target) {

        auto ans = find(nums.begin(), nums.end(), target);
        if (ans == nums.end()) return -1;
        else return ans-nums.begin();
    }
};
