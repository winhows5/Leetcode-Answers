/* time cost: 6ms (87.94%) */
/* time complexity: O(n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int longestValidParentheses(string s) {
        int max(0);
        int cnt(0);
        int lgh_t(0);
        int lgh_t0(0);
        stack<pair<int, int>> lgh_all;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                ++cnt;
            if (s[i] == ')') {
                --cnt;
                if (cnt < 0 && lgh_all.empty()) {
                    lgh_t = 0;
                    lgh_t0 = 0;
                    cnt = 0;
                    continue;
                }
                else if (cnt >= 0) {
                    lgh_all.push(make_pair(cnt, 2));
                    cnt = 0;
                    if (lgh_all.top().second > max)
                        max = lgh_all.top().second;
                }
                else {
                    --lgh_all.top().first;
                    lgh_all.top().second += 2;
                    if (lgh_all.top().second > max)
                        max = lgh_all.top().second;
                    cnt = 0;
                }
                if (lgh_all.top().first == 0) {
                    lgh_t += lgh_all.top().second;
                    lgh_all.pop();
                    if (lgh_all.empty()) {
                        lgh_t0 += lgh_t;
                        if (lgh_t0 > max) max = lgh_t0;
                        lgh_t = 0;
                    }
                    else {
                        lgh_all.top().second += lgh_t;
                        lgh_t = 0;
                        if (lgh_all.top().second > max)
                            max = lgh_all.top().second;
                    }
                }
            }
        }
        return max;
    }
};
