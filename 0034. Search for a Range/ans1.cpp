/* time cost: 7ms (99.29%)    */
/* time complexity: O(log(n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid, mid2;
        vector<int> ans;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else if (nums[mid] < target)
                start = mid + 1;
            else {
                mid2 = mid;
                while (mid > 0 && nums[mid - 1] == nums[mid])
                    --mid;
                ans.push_back(mid);
                while (mid2 + 1 < nums.size() && nums[mid2 + 1] == nums[mid2])
                    ++mid2;
                ans.push_back(mid2);
                return ans;
                
            }
        }
        return {-1, -1};
    }
};
