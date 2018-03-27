/* time cost: 15ms (90.73%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lngth = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (i + 2 < nums.size() && nums[i+2] == nums[i]) ++i;
            ++lngth;
            nums[lngth-1] = nums[i];
        }
        return lngth;
    }
};
