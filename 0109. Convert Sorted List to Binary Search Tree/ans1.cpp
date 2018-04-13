/* time cost: 20ms (100.00%) */
/* time complexity: O(n)     */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* creatBST(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;
        ListNode* tmp_tail = head, *tmp_head = head;
        while (tmp_tail != tail && tmp_tail->next != tail) {
            tmp_head = tmp_head->next;
            tmp_tail = tmp_tail->next->next;
        }
        TreeNode* root = new TreeNode(tmp_head->val);
        root->left = creatBST(head, tmp_head);
        root->right = creatBST(tmp_head->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return creatBST(head, nullptr);
    }
};
