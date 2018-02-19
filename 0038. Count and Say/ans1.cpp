/* time cost: 2ms (88.61%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        else {
            string s = countAndSay(--n);
            string ans = "";
            int cnt = 0;
            char c = s[0];
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == c) {
                    ++cnt;
                }
                else {
                    ans += to_string(cnt);
                    ans += c;
                    c = s[i];
                    cnt = 1;
                }
                if (i == s.size() - 1) {
                    ans += to_string(cnt);
                    ans += c;
                }
            }
            return ans;
        }
    }
};
