/* time cost: 12ms (63.65%) */
/* time complexity: O(n^k)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> t_ans;
        vector<vector<int>> ans;
        helper(candidates, ans, t_ans, target, 0);
        return ans;   
    }
    
    void helper(vector<int>& candidates,vector<vector<int>> &ans,vector<int> &t_ans, int target, int cur) {
        if (target == 0) {
            ans.push_back(t_ans);
            return;
        }
        
        for (int i=cur; i<candidates.size() && candidates[i]<=target; ++i) {
            t_ans.push_back(candidates[i]);
            helper(candidates, ans, t_ans, target-candidates[i], i);
            t_ans.pop_back();
        }
    }
};
