/* time cost: 16ms (97.18%) */
/* time complexity: O(n^2log(n)) */

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
    vector<TreeNode*> iteration(int small, int great) {
        vector<TreeNode*> res;
        if (small > great)
            return vector<TreeNode*>{nullptr};
        if (small == great)
            return vector<TreeNode*>{new TreeNode(small)};
        
        for (int i = small; i <= great; ++i) {
            vector<TreeNode*> left = iteration(small, i-1);
            vector<TreeNode*> right = iteration(i+1, great);
            for (TreeNode* l : left)
                for (TreeNode* r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>{};
        return iteration(1, n);
        
    }
};
