/* time cost: 7ms (100.00%) */
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;      
        bool first = false;
        ListNode nHead(INT_MAX), *pre = &nHead, *cur;
        nHead.next = head;
        while (pre && pre->next) {
            cur = pre->next;
            bool skip = false;
            while (cur) {
                while (cur->next != NULL && cur->val == cur->next->val) {
                    cur = cur->next;
                    skip = true;
                }
                if (skip)  {
                    cur = cur->next;
                    skip = false;
                    if (!first) head = cur;
                }
                else break;
            }
            if (!first) {
                first = true;
                pre = head;
                continue;
            }
            pre->next = cur;
            pre = pre->next;
        }
        return head;
    }
};
