/* time cost: 3ms (98.42%) */
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
    int sumNumbers(TreeNode* root) {
        stack<TreeNode*> nodes;
        TreeNode* cur = root, *mark = nullptr;
        int ans = 0;
        int num = 0;
        while (cur || !nodes.empty()) {
            if (cur) {
                num = num * 10 + cur->val;
                nodes.push(cur);
                cur = cur->left;
            }
            else {
                cur = nodes.top();
                if (cur->right && cur->right != mark) {
                    cur = cur->right;
                    num = num * 10 + cur->val;
                    nodes.push(cur);
                    cur = cur->left;
                }
                else {
                    if (!cur->right && !cur->left) ans += num;
                    nodes.pop();
                    mark = cur;
                    cur = nullptr;
                    num /= 10;
                }
            }
        }
        return ans;
    }
};
