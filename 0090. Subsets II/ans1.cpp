/* time cost: 9ms (99.57%) */
/* time complexity: O(2^n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void iteration (vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int start) {
        ans.push_back(temp);
        for (int i = start; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            if (!(i > start && nums[i] == nums[i-1]))
                iteration(ans, temp, nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        iteration(ans, temp, nums, 0);
        return ans;
    }
};
