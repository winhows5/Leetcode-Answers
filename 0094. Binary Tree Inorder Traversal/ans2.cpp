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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stack_of_node;
        TreeNode *temp = root;
        while (!stack_of_node.empty() || temp) {
            if (temp) {
                stack_of_node.push(temp);
                temp = temp->left;
            }
            else {
                temp = stack_of_node.top();
                ans.push_back(temp->val);
                temp = temp->right;
                stack_of_node.pop();
            }
        }
        
        return ans;
    }
};
