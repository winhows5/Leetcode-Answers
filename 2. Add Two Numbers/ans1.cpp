/* time cost: 25ms (99.63%) */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode prehead(0);
        ListNode *nans = &prehead, *nl1 = l1, *nl2 = l2;

        while (1) {
            if (nl1 == NULL && nl2 == NULL) {
                if ( carry == 1)
                    nans->next = new ListNode(1);
                return prehead.next;
            }
            else if ( nl1 == NULL && nl2 != NULL) {
                nans->next = new ListNode((carry + nl2->val) % 10);
                carry = (carry + nl2->val) / 10;
                nans = nans->next;
                nl2 = nl2->next;
            }
            else if ( nl1 != NULL && nl2 == NULL) {
                nans->next = new ListNode((carry + nl1->val) % 10);
                carry = (carry + nl1->val) / 10;
                nans = nans->next;
                nl1 = nl1->next;
            }
            else {
                nans->next = new ListNode((carry + nl1->val + nl2->val) % 10);
                carry = (carry + nl1->val + nl2->val) / 10;
                nans = nans->next;
                nl1 = nl1->next;
                nl2 = nl2->next;
                
            }
        }
    }
};
