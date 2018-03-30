/* time cost: 3ms (95.00%) */
/* time complexity: O(n)   */

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
    void iteration(vector<int> &ans, TreeNode *root) {
        if (root == nullptr) return;
        iteration(ans, root->left);
        ans.push_back(root->val);
        iteration(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        iteration(ans, root);
        return ans;
    }
};
