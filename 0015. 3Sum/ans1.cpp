/* time cost: 96ms (98.50%) */
/* time complexity: O(n^2)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int sum2, left, right;
        int longth = nums.size();
        for(int i = 0; i < longth; ++i) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            sum2 = - nums[i];
            left = i + 1;
            right = longth - 1;
            while(left < right) {
                if (nums[left] + nums[right] == sum2) {                   
                    ans.push_back({nums[i], nums[left], nums[right]});
                    do { ++left;
                    } while(left > i + 1 && nums[left-1] == nums[left]);
                    do { --right;
                    }while(right < longth + 1 && nums[right+1] == nums[right]);                    
                }
                else if (nums[left] + nums[right] < sum2) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
        return ans;
    }
};
