/* time cost: 4ms (99.31%)    */
/* time complexity: O(log(n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int lgh = nums.size();
        int start = 0;
        int end = lgh - 1;
        int mid;
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[end] < nums[mid]) start = mid + 1;
            else end = mid;
        }
        int pivot = start;
        int start_num = 0;
        int end_num = lgh - 1;
        int m;
        while (start_num <= end_num) {
            m = (start_num + end_num) / 2;
            mid = ( m + pivot ) % lgh;
            if (nums[mid] > target) end_num = m - 1;
            else if (nums[mid] < target) start_num = m + 1;
            else return mid;
        }
        return -1;
    }
};
