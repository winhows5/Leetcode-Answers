/* time cost: 3ms (99.86%) */
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* t = head;
        while(--n) {
            t = t->next;
        }
        ListNode** d = &head;
        while(t->next != NULL) {
            d = &((*d)->next);
            t = t->next;
        }
        *d = (*d)->next;
        return head;
    }
};
