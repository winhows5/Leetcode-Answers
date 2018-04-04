/* time cost: 6ms (99.93%) */
/* time complexity: O(m+n) */

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        TreeNode *l_root = root->left, *r_root = root->right;
        if (l_root == nullptr ^ r_root == nullptr) return false;
        if (l_root == nullptr && r_root == nullptr) return true;
        queue<TreeNode*> l_nodes, r_nodes;
        l_nodes.push(l_root);
        r_nodes.push(r_root);
        while(!l_nodes.empty() && !r_nodes.empty()) {
            l_root = l_nodes.front();
            r_root = r_nodes.front();
            if (l_root->val != r_root->val) return false;
            if (l_root->left && r_root->right) {
                l_nodes.push(l_root->left);
                r_nodes.push(r_root->right);
            }
            else if (l_root->left == nullptr ^ r_root->right == nullptr) return false;
            if (l_root->right && r_root->left) {
                l_nodes.push(l_root->right);
                r_nodes.push(r_root->left);
            }
            else if (l_root->right == nullptr ^ r_root->left == nullptr) return false;  
            l_nodes.pop();
            r_nodes.pop();
        }
        if (l_nodes.empty() ^ r_nodes.empty()) return false;
        return true;
    }
};
