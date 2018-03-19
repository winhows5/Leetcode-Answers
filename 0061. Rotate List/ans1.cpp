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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode preHead(-1);
        ListNode mid(-1);
        preHead.next = head;
        int lgh = 1;
        while (head->next) {
            head = head->next;
            ++lgh;
        }
        int cnt = lgh - k % lgh;
        if (cnt == lgh) return preHead.next;
        head->next = preHead.next;
        while(--cnt) {
            preHead.next = (preHead.next)->next;
        }
        mid.next = (preHead.next)->next;
        (preHead.next)->next = NULL;
        return mid.next;
    }
};
