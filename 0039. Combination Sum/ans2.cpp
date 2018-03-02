/* time cost: 15ms (41.65%) */
/* time complexity: O(k^n)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> t_ans;
        sort(candidates.begin(), candidates.end());
        iteration(candidates, 0, target, t_ans, ans);
        return ans;
    }
    
    void iteration(vector<int> candidates, int ind, int target, vector<int> t_ans, vector<vector<int>> &ans) {
        if (ind == candidates.size()) return;
        int t = candidates[ind];
        while(target >= 0) {
            if (target == 0) {
                ans.push_back(t_ans);
                return;
            }
            if (target < t) return;
            iteration(candidates, ind + 1, target, t_ans, ans);
            target -= t;
            t_ans.push_back(t);
        }
    }
};
