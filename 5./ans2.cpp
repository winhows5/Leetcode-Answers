/* time cost: 9ms (77.04%) */
/* time complexity: O(n^2) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string longestPalindrome(string &s) {
    int longth = 0, iBegin = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; ; ++j) {
            if( i-j >= 0 && i+j <= n -1 && s[i-j] == s[i+j]) {
                if (2*j + 1 > longth) {
                    longth = 2 * j + 1;
                    iBegin = i - j;
                    
                }
            } else break;
        }
        if (i-1 >= 0 && s[i-1] == s[i]) {
            for (int j = 0; ; ++j) {
                if( i-1-j >= 0 && i+j <= n -1 && s[i-1-j] == s[i+j]) {
                    if (2*j + 2 > longth) {
                        longth = 2 * j + 2;
                        iBegin = i - 1 - j;
                        
                    }
                } else break;
            }
        }
    }
    
    return s.substr(iBegin, longth);
}
};
