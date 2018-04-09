/* time cost: 4ms (100.00%) */
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>{};
        vector<vector<int>> ans;
        vector<int> ans_tmp;
        stack<TreeNode*> dir_left, dir_right;
        dir_left.push(root);
        TreeNode* cur;
        while(true) {
            ans_tmp = {};
            while(!dir_left.empty()) {
                cur = dir_left.top();
                dir_left.pop();
                ans_tmp.push_back(cur->val);
                if (cur->left) dir_right.push(cur->left);
                if (cur->right) dir_right.push(cur->right);
            }
            if (ans_tmp.empty()) return ans;
            ans.push_back(ans_tmp);
            ans_tmp = {};
            while(!dir_right.empty()) {
                cur = dir_right.top();
                dir_right.pop();
                ans_tmp.push_back(cur->val);
                if (cur->right) dir_left.push(cur->right);
                if (cur->left) dir_left.push(cur->left);
            }
            if (ans_tmp.empty()) return ans;
            ans.push_back(ans_tmp);
        }
        
    }
};
