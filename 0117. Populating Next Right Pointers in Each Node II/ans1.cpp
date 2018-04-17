/* time cost: 23ms (99.91%) */
/* time complexity: O(n)    */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> nodes;
        nodes.push(root);
        TreeLinkNode *pre, *cur;
        while(!nodes.empty()) {
            int n = nodes.size();
            pre = nodes.front();
            for (int i = 0; i < n; ++i) {
                cur = nodes.front();
                nodes.pop();
                if (cur->left) nodes.push(cur->left);
                if (cur->right) nodes.push(cur->right);
                if (i != 0) pre->next = cur;
                pre = cur;
            }
            cur->next = nullptr;
        }
    }
};
