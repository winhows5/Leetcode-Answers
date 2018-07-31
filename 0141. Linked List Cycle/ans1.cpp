/* time cost: 4ms (100%) */
/* time complexity: O(n) */

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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode* slow_p = head->next;
        ListNode* fast_p = head->next->next;
        while (fast_p != slow_p) {
            if (fast_p == nullptr || fast_p->next == nullptr) return false;
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
        }
        return true;
    }
};
