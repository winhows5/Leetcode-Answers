/* time cost: 45ms (99.85%) */
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
    void recoverTree(TreeNode* root) {
        bool mark = true;
        bool once = true;
        int value;
        TreeNode *rt, *cur = root, *pre;
        vector<TreeNode*> mistakes;
        while(cur) {
            if (cur->left == nullptr) {
                if (mark) {mark = false; value = cur->val;}
                else if (value >= cur->val && once) {
                    mistakes.push_back(pre);
                    mistakes.push_back(cur);
                    once = false;
                    value = cur->val;
                }
                else if (value >= cur->val) {
                    mistakes.back() = cur;
                }
                else value = cur->val;
                pre = cur;
                cur = cur->right;
            }
            else {
                rt = cur->left;
                while (rt->right && rt->right != cur)
                    rt = rt->right;
                if (rt->right == nullptr) {
                    rt->right = cur; 
                    cur = cur->left;
                }
                else {
                    rt->right = nullptr;
                    if (value >= cur->val && once) {
                        mistakes.push_back(pre);
                        mistakes.push_back(cur);
                        once = false;
                        value = cur->val;
                    }
                    else if (value >= cur->val) {
                        mistakes.back() = cur;
                    }
                    else value = cur->val;  
                    pre = cur;
                    cur = cur->right;   
                }
            }
        }
        
        swap(mistakes.front()->val, mistakes.back()->val);
    }
};
