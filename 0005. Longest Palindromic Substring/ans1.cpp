/* time cost: 3ms (93.89%) */
/* time complexity: O(n^2) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string longestPalindrome(string &s) {
    int longth = 0, iHead = 0, iBegin = 0, iEnd = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
        iBegin = i;
      
        // ahhhh WONDERFUL! 
        while (i+1 < n && s[i+1] == s[i]) ++i;
        iEnd = i;
        
        while (iBegin >= 0 && iEnd < n && s[iBegin] == s[iEnd]) {
            --iBegin;
            ++iEnd;
        }
        if (iEnd - iBegin - 1 > longth) {
            longth = iEnd - iBegin - 1;
            iHead = iBegin + 1;   
        }
    }
    
    return s.substr(iHead, longth);
}
};
