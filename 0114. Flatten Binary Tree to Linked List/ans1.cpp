/* time cost: 7ms (100.00%) */
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
    void flatten(TreeNode* root) {
        while(root) {
            if (root->left) {
                TreeNode* r = root->right, *l = root->left;
                root->left = nullptr;
                root->right = l;
                while(l->right) l = l->right;
                l->right = r;
                root = root->right;
            }
            else root = root->right;
        }
    }
};
