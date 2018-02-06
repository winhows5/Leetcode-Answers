/* time cost: 10ms (85.91%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lgh = nums.size();
        int max = nums[lgh-1];
        for (int i = lgh-1; i >= 0; --i) {
            
            if (nums[i] >= max) {
                if (i == 0) {
                    reverse(nums.begin(), nums.end());
                    break;
                }
                max = nums[i];
                continue;
            }
            else {
                for (int j = i + 1; j < lgh; ++j) {
                    if (j + 1 == lgh || nums[j+1] <= nums[i]) {
                        int temp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = temp;
                        break;
                    }
                }
                reverse(nums.begin() + i + 1, nums.end());
                break;
            }
        }
    }
};
