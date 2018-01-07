/* time cost: 5ms (61.14%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int i = -1;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
