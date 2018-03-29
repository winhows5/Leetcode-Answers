/* time cost: 5ms (55.38%) */
/* time complexity: O(n)   */

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) return head;
        ListNode new_head(0), *ptr_m = &new_head, *ptr_n, *ptr_temp;
        new_head.next = head;
        while (--m && ptr_m->next) {
            --n;
            ptr_m = ptr_m->next;
        }
        if (ptr_m->next == NULL || ptr_m->next->next == NULL) return head;
        
        ptr_n = ptr_m->next;
        while (--n) {
            ptr_temp = ptr_n->next;
            ptr_n->next = ptr_temp->next;
            ptr_temp->next = ptr_m->next;
            ptr_m->next = ptr_temp;
            if (ptr_n->next == NULL) break;
        }
   
        return new_head.next;
    }
};
