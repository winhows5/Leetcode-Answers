/* Dynamic Program */
/* time cost: 44ms (63.27%) */
/* time complexity: O(nm) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_long = s.size(), p_long = p.size();
        vector<bool> prev(p_long + 1, false); 
        prev[0] = true;
        for(int j = 1; j <= p_long; ++j)
            prev[j] = prev[j-1] && p[j-1]=='*';
        for(int i = 1; i <= s_long; ++i) {
            vector<bool> cur(p_long+1, false);
            for(int j = 1; j <= p_long; ++j) {
                if(p[j-1] == '*') {
                    cur[j] = cur[j-1] || prev[j]; // prev[j] means the status at i-1
                }
                else {
                    cur[j] = prev[j-1] && (s[i-1]==p[j-1] || p[j-1]=='?');
                }
            }
            prev = cur;
        }
        return prev[p_long];
    }
};
