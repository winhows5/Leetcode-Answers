/* time cost: 7ms (84.03%) */
/* time complexity: O(2^n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> t_ans;
        iteration(candidates, target, 0, t_ans, ans);
        return ans;
    }
    
    void iteration(vector<int>& candidates, int target, int ind, vector<int> &t_ans, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(t_ans);
            return;
        }
        if (ind == candidates.size()) return;
        for (int i = ind; i < candidates.size() && candidates[i] <= target; ++i) {
            if (i >  0 && candidates[i] == candidates[i-1] && i > ind) continue;
            t_ans.push_back(candidates[i]);
            iteration(candidates, target-candidates[i], i + 1, t_ans, ans);
            t_ans.pop_back();
        } 
    }
};
