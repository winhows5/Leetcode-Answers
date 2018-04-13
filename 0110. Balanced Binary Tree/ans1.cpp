/* time cost: 8ms (99.71%) */
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
    int getDepth(TreeNode* root) {
        return root == nullptr ? 0 : max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return root == nullptr ? true : (isBalanced(root->left) && isBalanced(root->right)
                                         && abs(getDepth(root->left) - getDepth(root->right)) <= 1);
    }
};
