/* time cost: 42ms (100.00%) */
/* time complexity: O(n)     */
 
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) return nullptr;
        RandomListNode *newH, *l1, *l2;
        for (l1 = head; l1 != nullptr; l1 = l1->next->next) {
            l2 = new RandomListNode (l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }
        newH = head->next;
        for (l1 = head; l1 != nullptr; l1 = l1->next->next) {
            if (l1->random) {
                l1->next->random = l1->random->next;
            }
        }
        for (l1 = head; l1 != nullptr; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next) l2->next = l2->next->next;
        }
        return newH;
    }
};
