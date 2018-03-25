/* time cost: 3ms (93.77%) */
/* time complexity: O(n)   */

static int  x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:

    int combination (int large, int small) {
        // small means the nums of 2
        // large means the nums of 2 and 1
        // ans = factorial(large) / (factorial(small) * factorial(large - small));
        if (small == 0) return 1;
        int _max = max(small, large - small);
        int _min = min(small, large - small);
        long long ans = 1;
        int j = 2;
        for (int i = _max + 1; i <= large; ++i) {
            if (_min >= j && i % j == 0) {
                ans = i / j * ans;
                ++j;
            } 
            else ans *= i;
            while (_min >= j && ans % j == 0) {
                ans /= j;
                ++j;
            }    
        }
        return ans;
        
    }
    
    int climbStairs(int n) {
        int ans = 0;
        int small = n / 2;
        int large = n / 2 + n % 2;
        for(; large <=n; ++large, --small) {
            ans += combination(large, small);
        }
        return ans;
    }
};
