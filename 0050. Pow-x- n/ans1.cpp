/* time cost: 4ms (98.84%)    */
/* time complexity: O(log(n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 0.0 || x == 1.0) return x;
        if (n == INT_MIN) {
            double sq = myPow(x, n/2);
            return sq * sq;
        }
        if (n < 0) {
            x = 1/x;
            n = -n;
        }
        double sq = myPow(x, n/2);
        if (n % 2 == 0)
            return sq * sq;
        else
            return sq * sq * x;
    }
};
