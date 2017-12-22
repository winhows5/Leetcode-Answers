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

// It works but not beautiful enough
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return head;
        int count = 1;
        ListNode* t = head;
        while(t = t->next) {
            ++count;
        }
        int del = count - n + 1;
        ListNode** d = &head;
        while(--del) {
            d = &((*d)->next);
        }
        (*d) = ((*d)->next);
        return head;
        
    }
};
