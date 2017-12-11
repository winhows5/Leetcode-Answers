/* time cost: 9ms (98.98%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while (x != 0) {
            // That's brilliant!
            ans = ans * 10 + x % 10;
            if (ans > INT_MAX || ans < INT_MIN) return 0;
            x /= 10;
        }
        
        return ans;
    }
};
