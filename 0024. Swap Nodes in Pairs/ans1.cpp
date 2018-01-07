/* time cost: 3ms (17.84%) */
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p;
        if (head == NULL || head->next == NULL) return head;
        ListNode* ans = head->next;
        while (head != NULL && head->next != NULL) {
            p = head->next->next;
            if (p == NULL || p->next == NULL) {
                head->next->next = head;
                head->next = p;
                head = head->next;
            }
            else {
                head->next->next = head;
                head->next = p->next;
                head = p;
            }
        }
        return ans;
    }
};
