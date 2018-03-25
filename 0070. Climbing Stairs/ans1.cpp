/* time cost: 3ms (93.77%) */
/* time complexity: O(n)   */

class Solution {
public:
    
    int climbStairs(int n) {
        if (n < 3) return n;
        int ans;
        int step1 = 1;
        int step2 = 2;
        for (int i = 3; i <= n; ++i) {
            ans = step1 + step2;
            step1 = step2;
            step2 = ans;
        }
        return ans;
    }
};
