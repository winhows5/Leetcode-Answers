/* time cost: 23ms (96.95%)        */
/* time complexity: O(Nlog(lists)) */

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

/* NEW POINT: priority queue */
struct int2 {
    int2();
    int2(int i, int j) {
        val = i;
        no = j;
    }
    int val;
    int no;
    friend bool operator< (const int2& lh, const int2& rh) {
        return lh.val > rh.val;
    }
};

class Solution {
public:
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        int m = 0;
        priority_queue<int2> found;
        for (int i = 0; i < n; ++i) {
            if (lists[i] == NULL) {
                ++m;
                continue;
            }
            found.push(int2(lists[i]->val, i));
        }
        ListNode Ans(0);
        ListNode* pAns = &Ans;
        while (m < n) {
            int2 t = found.top();
            found.pop();
            pAns->next = lists[t.no];
            pAns = pAns->next;
            if (lists[t.no]->next == NULL) 
                ++m;
            else {
                lists[t.no] = lists[t.no]->next;
                found.push(int2(lists[t.no]->val, t.no));
            }      
        }
        return Ans.next;
    }
};
