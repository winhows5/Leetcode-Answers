/* time cost: 16ms (99.98%) */
/* time complexity: O(n)    */

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 0 || k == 1) return head;
        int count = k;
        ListNode* p = head;
        while(--count) {
            if (p == NULL || p->next == NULL) return head;
            p = p->next;
        }
        ListNode* ans = p;
        
        p = head;
        while(1) {
            ListNode* nEnd = p;
            ListNode* pNext = p->next;
            ListNode* pNext2 = p->next->next;
            count = k;
            while(--count) {
                pNext->next = p;
                p = pNext;
                pNext = pNext2;
                if (pNext2 == NULL) break;
                else pNext2 = pNext2->next;
            }
            
            ListNode* p2 = pNext;
            count = k; 
            while(--count) {
                if (p2 == NULL || p2->next == NULL) {
                    nEnd->next = pNext; // new Head
                    return ans;
                }
                p2 = p2->next;
            }
            
            p = pNext;
            nEnd->next = p2;        
        }
    }
};
