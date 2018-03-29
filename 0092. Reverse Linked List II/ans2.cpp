/* time cost: 6ms (14.69%) */
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
        ListNode new_head(0), *ptr_m = &new_head, *ptr_n, *ptr_temp_l, *ptr_temp_r;
        new_head.next = head;
        while (--m && ptr_m->next) {
            --n;
            ptr_m = ptr_m->next;
        }
        if (ptr_m->next == NULL || ptr_m->next->next == NULL) return head;
        
        ptr_temp_l = ptr_m->next;
        ptr_n = ptr_m->next->next;
        ptr_temp_r = ptr_n->next;
        while (--n) {
            ptr_n->next = ptr_temp_l;
            ptr_temp_l = ptr_n;
            ptr_n = ptr_temp_r;
            if (ptr_n == NULL) break;
            ptr_temp_r = ptr_temp_r->next;
        }
        ptr_m->next->next = ptr_n;
        ptr_m->next = ptr_temp_l;    
        return new_head.next;
    }
};
