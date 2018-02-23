/* time cost: 26ms (38.28%) */
/* time complexity:  O(n^2) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int size = nums.size();
        permuteUniqueRecursion(nums, 0, ans, size);
        return ans;
    }
    

    void permuteUniqueRecursion(vector<int> nums, int ind, vector<vector<int>> &ans, int &size) {
        if (ind == size - 1) {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < size; ++i) {
            if (i > ind && nums[i] == nums[ind]) {
                continue;
            }
            swap(nums[ind], nums[i]);
            permuteUniqueRecursion(nums, ind + 1, ans, size);
            // swap(nums[ind], nums[i]);
        }
    }
};


