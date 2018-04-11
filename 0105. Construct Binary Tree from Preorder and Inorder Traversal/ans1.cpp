/* time cost: 15ms (87.43%) */
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
    TreeNode* iteration(vector<int>& preorder, vector<int>& inorder, int pre, int in1, int in2) {
        if (in1 > in2) return nullptr;
        TreeNode *root = new TreeNode(preorder[pre]);
        int pos = in1;
        while(pos <= in2 && root->val != inorder[pos]) ++pos;
        root->left = iteration(preorder, inorder, pre+1, in1, pos-1);
        root->right = iteration(preorder, inorder, pre+pos-in1+1, pos+1, in2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        TreeNode *root = iteration(preorder, inorder, 0, 0, preorder.size()-1);
        return root;
    }
};
