/* time cost: 6ms (100.00%) */
/* time complexity: O(n)    */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return nullptr;
        ListNode small(0), great(0), 
                 *s_cur = &small, *g_cur = &great, 
                 *cur = head;
        while(cur) {
            if (cur->val < x) {
                s_cur->next = cur;
                s_cur = s_cur->next;
            }
            else {
                g_cur->next = cur;
                g_cur = g_cur->next;
            }
            cur = cur->next;
        }
        g_cur->next = nullptr;
        s_cur->next = great.next;
        return small.next;
    }
};
