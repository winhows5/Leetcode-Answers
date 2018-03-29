/* time cost: 4ms (99.77%)       */
/* time complexity: O(n^2log(n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // s1.size() == s2.size()
        int lng = s1.size();
        if (lng == 1)
            if (s1 == s2) return true;
            else return false;
        
        int chr[26]{};
        for (int i = 0; i < lng; ++i) {
            ++chr[s1[i]-'a'];
            --chr[s2[i]-'a'];
        }
        for (int i = 0; i < 26; ++i) 
            if (chr[i] != 0) return false;
        
        for (int i = 1; i < lng; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i, lng-i), s2.substr(i, lng-i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(lng-i, i)) &&
                isScramble(s1.substr(i, lng-i), s2.substr(0, lng-i)))
                return true;
        }
        return false;
        
    }
};
