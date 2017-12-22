/* time cost: 25ms (99.91%) */
/* time complexity: O(n)    */

// The top1 answer of this problem is interesting...

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string intToRoman(int num) {
        int a0 = num % 10;
        int a1 = num / 10 % 10;
        int a2 = num / 100 % 10;
        int a3 = num / 1000;
        string r[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        string ans = r[3][a3] + r[2][a2] + r[1][a1] + r[0][a0];
        return ans;
    }
};
