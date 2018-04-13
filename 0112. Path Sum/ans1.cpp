/* time cost: 9ms (99.37%) */
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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int path_sum = 0;
        stack<TreeNode*> nodes;
        TreeNode* tmp = root, *mark = root;
        while(tmp || !nodes.empty()) {
            if (tmp) {
                nodes.push(tmp);
                path_sum += tmp->val;
                tmp = tmp->left;
            }
            else {
                tmp = nodes.top();
                if(tmp->right && tmp->right != mark) {
                    tmp = tmp->right;
                    path_sum += tmp->val;
                    nodes.push(tmp);
                    tmp = tmp->left;
                }
                else {
                    mark = tmp;
                    if (tmp->right == nullptr && tmp->left == nullptr && path_sum == sum)
                        return true;
                    path_sum -= tmp->val;
                    nodes.pop();
                    tmp = nullptr;
                }
            }
        }
        return false;
    }
};
