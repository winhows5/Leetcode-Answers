/* time cost: 6ms (99.70%) */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode Ans(-1);
        ListNode *pAns = &Ans;
        while(1) {
            if (l1 == NULL) {
                pAns->next = l2;
                return Ans.next;
            }
            if (l2 == NULL) {
                pAns->next = l1;
                return Ans.next;
            }
            if (l1->val < l2->val) {
                pAns->next = l1;
                l1 = l1->next;
            }
            else {
                pAns->next = l2;
                l2 = l2->next;
            }
            pAns = pAns->next;

        }     
    }
};
