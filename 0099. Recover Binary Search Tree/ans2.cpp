/* time cost: 47ms (98.78%) */
/* time complexity: O(logn) */

// Forgot to use O(1) space...
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
    void recoverTree(TreeNode* root) {
        bool mark = true;
        bool once = true;
        int value;
        TreeNode *cur = root, *pre;
        vector<TreeNode*> mistakes;
        stack<TreeNode*> nodes;
        while(!nodes.empty() || cur) {
            if (cur) {
                if (mark) value = cur->val;
                nodes.push(cur);
                cur = cur->left;
            }
            else {
                cur = nodes.top();
                if (mark) mark = false;
                else if (value >= cur->val && once) {
                    mistakes.push_back(pre);
                    mistakes.push_back(cur);
                    once = false;
                    value = cur->val;
                }
                else if (value >= cur->val) {
                    mistakes.back() = cur;

                    break;
                }
                else value = cur->val;
                pre = cur;
                cur = cur->right;
                nodes.pop();
            }
        }
        swap(mistakes.front()->val, mistakes.back()->val);
    }
};
