/* time cost: 12ms (53.87%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteRecursion(nums, 0, ans);
        return ans;
    }
    
    void permuteRecursion(vector<int> &nums, int ind, vector<vector<int>> &ans) {
        if (ind == nums.size()-1) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = ind; i < nums.size(); ++i) {
            swap(nums[ind],nums[i]);
            permuteRecursion(nums, ind + 1, ans);
            swap(nums[ind],nums[i]);
        }
    }
};
