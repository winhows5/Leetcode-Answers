/* time cost: 6ms (99.65%) */
/* time complexity: O(n)      */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int reverse(int x) {
        bool sg = 1;
        if (x < 0) {
            sg = 0;
            x = -x;
        }
        string s = to_string(x);
        char c;
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            c = s[i]; s[i] = s[j]; s[j] = c;
        }
        long ans = stol(s);
        if (ans + sg > 2147483648)
            return 0;
        else return sg ? ans : -ans;
    }
};
