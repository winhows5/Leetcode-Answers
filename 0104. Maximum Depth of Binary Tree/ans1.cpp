/* time cost: 5ms (99.84%) */
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> rows;
        rows.push(root);
        int depth = 0;
        while(!rows.empty()) {
            ++depth;
            int lngth = rows.size();
            for (int i = 0; i < lngth; ++i) {
                TreeNode *node = rows.front();
                rows.pop();
                if (node->left) rows.push(node->left);
                if (node->right) rows.push(node->right);
            }
        }
        return depth;
    }
};
