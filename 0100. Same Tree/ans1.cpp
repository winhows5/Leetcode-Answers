/* time cost: 3ms (97.75%) */
/* time complexity: O(n+m) */

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) return p == nullptr && q == nullptr;
        else if (p->val != q->val) return false;
        queue<TreeNode*> p_tree, q_tree;
        p_tree.push(p);
        q_tree.push(q);
        TreeNode *p_cur, *q_cur;
        while (!p_tree.empty() && !q_tree.empty()) {
            p_cur = p_tree.front();
            p_tree.pop();
            q_cur = q_tree.front();
            q_tree.pop();
            if (p_cur->left && q_cur->left) 
                if (p_cur->left->val == q_cur->left->val){
                    p_tree.push(p_cur->left);
                    q_tree.push(q_cur->left);
                }
                else return false;
            else if (p_cur->left == nullptr ^ q_cur->left == nullptr) return false;
            
            if (p_cur->right && q_cur->right) 
                if (p_cur->right->val == q_cur->right->val) {
                    p_tree.push(p_cur->right);
                    q_tree.push(q_cur->right);
                }
                else return false;
            else if (p_cur->right == nullptr ^ q_cur->right == nullptr) return false;
        }
        if (p_tree.empty() ^ q_tree.empty()) return false;
        return true;
    }
};
