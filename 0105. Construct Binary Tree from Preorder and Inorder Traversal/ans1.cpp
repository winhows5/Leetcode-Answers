/* time cost:  20ms (61.59%) */
/* time complexity: O(n)     */

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
    TreeNode* iteration(vector<int>& preorder, vector<int>& inorder, int p1, int p2, int i1, int i2) {
        if (p1 > p2 || i1 > i2) return nullptr;
        TreeNode *root = new TreeNode(preorder[p1]);
        int pos = i1;
        while(pos <= i2 && preorder[p1] != inorder[pos]) ++pos;
        root->left = iteration(preorder, inorder, p1+1, p1+pos-i1, i1, pos-1);
        root->right = iteration(preorder, inorder, p1+pos-i1+1, p2, pos+1, i2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        TreeNode *root = iteration(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
        return root;
    }
};
