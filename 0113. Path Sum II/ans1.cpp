/* time cost: 10ms (100.00%) */
/* time complexity: O(n)     */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        TreeNode *tmp = root, *mark = root;
        vector<vector<int>> ans;
        vector<int> ans_tmp;
        int path_sum = 0;
        stack<TreeNode*> nodes;
        while(tmp || !nodes.empty()) {
            if (tmp) {
                path_sum += tmp->val;
                nodes.push(tmp);
                ans_tmp.push_back(tmp->val);
                tmp = tmp->left;
            }
            else {
                tmp = nodes.top();
                if (tmp->right && tmp->right != mark) {
                    tmp = tmp->right;
                    path_sum += tmp->val;
                    nodes.push(tmp);
                    ans_tmp.push_back(tmp->val);
                    tmp = tmp->left;
                }
                else {
                    nodes.pop();
                    if (tmp->left == nullptr && tmp->right == nullptr && path_sum == sum)     
                        ans.push_back(ans_tmp);
                    path_sum -= tmp->val;
                    ans_tmp.pop_back();
                    mark = tmp;
                    tmp = nullptr;
                }
            }
        }
        return ans;
    }
};
