/* time cost: 16ms (98.93%)   */
/* time complexity: O(log(n)) */

// Integer Newton 
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return x;
        long r = x;
        long a = x;
        while (r*r > x) {
            r = (r + x / r) / 2;
        }
        return r;
    }
};
