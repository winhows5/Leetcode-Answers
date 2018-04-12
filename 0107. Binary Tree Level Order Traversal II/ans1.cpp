/* time cost: 6ms (96.60%) */
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
    void traversal(vector<vector<int>> &res, TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (depth == res.size()) res.push_back(vector<int>{});
        res[depth].push_back(root->val);
        traversal(res, root->left, depth+1);
        traversal(res, root->right, depth+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        traversal(res, root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};
