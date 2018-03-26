/* time cost: 4ms (99.95%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz = nums.size();
        int zero = 0, two = sz - 1;
        for (int i = 0; i <= two; ++i) {
            while (nums[i] == 2 && two > i) {
                swap(nums[i], nums[two]); 
                --two;
            }
            while (nums[i] == 0 && zero < i) {
                swap(nums[i], nums[zero]); 
                
                ++zero;
            }
        }
    }
};
