/* time cost: 5ms (99.90%)    */
/* time complexity: O(log(n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lngth = nums.size();
        if (lngth == 0) return false;
        int mid;
        int start = 0, end = lngth - 1;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[end]) {
                if (nums[mid] > target && nums[start] <= target) end = mid;
                else start = mid + 1;
            }
            else if (nums[mid] < nums[end]) {
                if (nums[mid] < target && nums[end] >= target) start = mid + 1;
                else end = mid;
            }
            else --end;
        }
        return nums[end] == target;
    }
};
