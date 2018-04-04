/* time cost: 8ms (99.86%) */
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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        TreeNode* tmp = root;
        int cmp;
        bool mark = true;

        TreeNode* cur = root;
        stack<TreeNode*> nodes;
        while(!nodes.empty() || cur) {
            if (cur) {
                if (mark) cmp = cur->val;
                nodes.push(cur);
                cur = cur->left;
            }
            else {
                cur = nodes.top();
                if (mark) mark = false;
                else if (cmp >= cur->val) return false;
                else cmp = cur->val;
                cur = cur->right;
                nodes.pop();
            }
        }
        return true;
    }
};
