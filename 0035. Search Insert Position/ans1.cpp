/* time cost: 4ms (99.73%)    */
/* time complexity: O(log(n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (start == mid) {
                if (nums[start] > target) return 0;
                else if (nums[end] < target) return nums.size();
                else if (nums[start] == target) return start;
                else return end;                   
            }
            if (nums[mid] > target) end = mid;
            else if (nums[mid] < target) start = mid;
            else return mid;
        }
    }
};
