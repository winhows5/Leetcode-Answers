/* time cost: 0ms (100.00%) */
/* time complexity: O(n) */
/* method: DFS */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        dfs(res, 0, root);
        return res;
    }
    
    void dfs(vector<int>& res, int level, TreeNode* node) {
        if (node == NULL) return;
        if (res.size() == level) res.push_back(node->val);
        dfs(res, level+1, node->right);
        dfs(res, level+1, node->left);
    }
};
