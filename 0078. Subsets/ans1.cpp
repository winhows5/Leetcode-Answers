/* time cost: 6ms (100.00%) */
/* time complexity: O(2^n)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void iteration (vector<int> &nums, vector<vector<int>> &ans, 
                    vector<int> &temp, int start) {
        ans.push_back(temp);
        for (int i = start; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            iteration(nums, ans, temp, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        iteration(nums, ans, temp, 0);
        return ans;
    }
};
