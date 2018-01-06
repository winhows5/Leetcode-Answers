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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode Ans(0);
        ListNode* pAns = &Ans;
        while(1) {
            if (l1 == NULL) {
                pAns->next = l2;
                return Ans.next;
            }
            else if (l2 == NULL) {
                pAns->next = l1;
                return Ans.next;
            }
            else if (l1->val < l2->val) {
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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        else {
            int d = 1;
            while (d < n) {
                for (int i = 0; i < n - d; i = i + 2*d) {
                    lists[i] = merge2Lists(lists[i], lists[i+d]);
                }
                d = d * 2;
            }
            return lists[0];
            
        }
    }
};
