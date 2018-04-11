/* time cost: 9ms (100.00%) */
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
    TreeNode* iteration(vector<int>& inorder, vector<int>& postorder, 
                        int in1, int in2, int po1, int po2) {
        if (in1 > in2 || po1 > po2) return nullptr;
        int pos = in2;
        TreeNode* root = new TreeNode(postorder[po2]);
        while (pos >= 0 && postorder[po2] != inorder[pos]) --pos;
        root->left = iteration(inorder, postorder, in1, pos-1, po1, po2-in2+pos-1);
        root->right = iteration(inorder, postorder, pos+1, in2, po2-in2+pos, po2-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return nullptr;
        TreeNode* root = iteration(inorder, postorder, 0, inorder.size()-1, 0, inorder.size()-1);
        return root;
    }
};
