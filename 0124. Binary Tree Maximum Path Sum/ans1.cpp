/* time cost: 19ms (99.75%) */
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
    int findMax(TreeNode* root, int &ans) {
        if (root == nullptr) return 0;
        int left = findMax(root->left, ans);
        int right = findMax(root->right, ans);
        if (left < 0) left = 0;
        if (right < 0) right = 0;
        if (left + right + root->val > ans) ans = left + right + root->val;
        return left > right ? left + root->val : right + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findMax(root, ans);
        return ans;
    }
};
