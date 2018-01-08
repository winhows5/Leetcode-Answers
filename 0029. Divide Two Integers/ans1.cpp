/* time cost: 9ms (99.07%)    */
/* time complexity: O(log(n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// It assumed that only INT(32-bit) type can be used in this code.
// If using LONG type, the code would be easier.
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor) return INT_MAX;
        if (divisor == INT_MIN) return divisor == dividend;
        bool sgn = (dividend<0) ^ (divisor<0);
        
        int ans = 0;
        if (dividend == INT_MIN) {
            if (divisor == -1) return INT_MAX;
            else if (divisor == 1) return INT_MIN;
            ++ans;
            dividend += abs(divisor);  
        }

        divisor = abs(divisor);
        dividend = abs(dividend);
        int mult = 0;
        int dsor = divisor;
        
        while(dividend >= divisor) {
            while (dividend >= (dsor<<1) && dsor <= INT_MAX>>1) {
                if (!mult) ++mult;
                mult <<= 1;
                dsor <<= 1;
            }
            if (!mult) ++mult;
            ans += mult;
            dividend -= dsor;
            dsor = divisor;
            mult = 0;  
        }
        return sgn ? -ans : ans; 
    }
};
