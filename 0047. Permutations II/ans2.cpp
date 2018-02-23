/* time cost: 26ms (38.28%) */
/* time complexity: O(n^2)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;
        permuteUniqueRecursion(nums, 0, ans);
        return ans;
    }
    

    void permuteUniqueRecursion(vector<int> &nums, int ind, vector<vector<int>> &ans) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_map<int, int> uni;
        for (int i = ind; i < nums.size(); ++i) {
            if (++uni[nums[i]] > 1) {
                continue;
            }
            swap(nums[ind], nums[i]);
            permuteUniqueRecursion(nums, ind + 1, ans);
            swap(nums[ind], nums[i]);
        }
    }
};

