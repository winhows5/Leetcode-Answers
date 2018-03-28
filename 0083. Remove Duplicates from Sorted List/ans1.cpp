/* time cost: 10ms (100.00%) */
/* time complexity: O(n)     */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return nullptr;
        ListNode nHead(INT_MAX), *pre = &nHead, *cur;
        nHead.next = head;
        while (pre && pre->next) {
            cur = pre->next;
            while (cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
            pre->next = cur;
            pre = pre->next;
            
        }
        return head;
    }
};
