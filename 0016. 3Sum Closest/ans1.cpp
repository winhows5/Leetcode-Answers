/* time cost: 6ms (81.02%) */
/* time complexity: O(n^2) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left, right;
        int diff = INT_MAX;
        int ans;
        int longth = nums.size();
        for(int i = 0; i < longth; ++i) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            left = i + 1;
            right = longth - 1;
            while(left < right) {
                if (nums[left] + nums[right] == target - nums[i]) {
                    return target;
                }
                else if (nums[left] + nums[right] < target - nums[i]) {
                    if(target - nums[i] - nums[left] - nums[right] < diff) {
                        diff = target - nums[i] - nums[left] - nums[right];
                        ans = nums[i] + nums[left] + nums[right];
                    }
                    ++left;
                }
                else {
                    if(nums[left] + nums[right] - target + nums[i] < diff) {
                        diff = nums[left] + nums[right] + nums[i] - target;
                        ans = nums[i] + nums[left] + nums[right];
                    }
                    --right;
                }
         
            }
        }
        return ans;
    }
};
