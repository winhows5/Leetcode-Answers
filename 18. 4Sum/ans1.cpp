/* time cost: 9ms (97.97%) */
/* time complexity: O(n^3) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int left, right, longth = nums.size();
        for (int i = 0; i < longth - 3; ++i) {
            if (nums[i] * 4 > target) break;
            if ((i > 0 && nums[i-1] == nums[i]) || nums[i] + 3 * nums.back() < target) continue;
            for (int j = i + 1; j < longth - 2; ++j) {
                if (nums[j] * 3 > target - nums[i]) break;
                if (j > i + 1 && nums[j-1] == nums[j]) continue;
                left = j + 1;
                right = longth - 1;
                while (left < right){
                    if (nums[left] + nums[right] == target - nums[i] - nums[j]) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;  
                    }
                    else if (nums[left] + nums[right] < target - nums[i] - nums[j])
                        ++left;
                    else
                        --right;
                    while(left-1 > j && nums[left-1] == nums[left]) 
                        ++left;
                    while(right+1 < longth && nums[right+1] == nums[right]) 
                        --right;  
                }
            }
        }
        return ans;
    }
};
