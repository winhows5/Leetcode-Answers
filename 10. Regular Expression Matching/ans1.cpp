/* time cost: 99ms (16.00%) */
/* time complexity: O((m+n)2^(m+n/2)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        bool front;
        if (!s.empty() && (s[0] == p[0] || p[0] == '.')) front = true;
        else front = false;
        
        if (p.size() >= 2 && p[1] == '*') 
            return   
                    isMatch(s, p.substr(2, p.size()-2)) ||
                    (front && isMatch(s.substr(1, s.size()-1), p));
        else return front && isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1)); 
        
    }
};
