/* Greedy Algorithm */
/* time cost: 17ms (100.00%) */
/* time complexity: O(n+m)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_long = s.size(), p_long = p.size();
        int i = 0 ,j = 0;
        int match;
        int risk = -1;
        while (i < s_long) {
            if (j < p_long && p[j] == '*') {
                match = i;
                risk = j++;
            }
            else if (j < p_long && (p[j] == s[i] || p[j] == '?')) {
                ++i;
                ++j;
            }
            else if (risk >= 0) {
                i = ++match;
                j = risk + 1;
            }
            else return false;
        }
        while (j < p_long && p[j] == '*') ++j;
        return j == p_long;
    }
};

