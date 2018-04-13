/* time cost: 5ms (100.00%) */
/* time complexity: O(n)    */

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int depth = 0;
        while(!nodes.empty()) {
            ++depth;
            int lngth = nodes.size();
            for (int i = 0; i < lngth; ++i) {
                TreeNode* tmp = nodes.front();
                if (tmp->left == nullptr && tmp->right == nullptr) {
                    return depth;
                }
                if (tmp->left) nodes.push(tmp->left);               
                if (tmp->right) nodes.push(tmp->right);
                nodes.pop();
            }
        }
    }
};
