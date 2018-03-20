/* time cost: 6ms (98.86%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        int loc = 0;
        int lgh = s.size();
        while (s[loc] == ' ') ++loc;
        while (s[lgh-1] == ' ') --lgh;
        if (loc >= lgh) return false;
        int point = 0;
        int e = 0;
        int num = 0;
        for (int i = loc; i < lgh; ++i) {
            if (s[i] == '-' || s[i] == '+') {
                if (i == lgh-1 || (i < lgh-1 && s[i+1] == 'e')) return false;
                else if (i < lgh-2 && s[i+1] == '.' && s[i+2] == 'e') return false;
                else if (i > loc && s[i-1] != 'e') return false;
            }
            else if (s[i] == '.') {
                ++point;
                if (point > 1) return false;
                if (e > 0) return false;
                if (num == 0) {
                    if (i == lgh-1) return false;
                    if (i < lgh - 1 && s[i+1] =='e') return false;
                }
            }
            else if (s[i] == 'e') {
                ++e;
                if (i == loc) return false;
                if (i == lgh - 1) return false;
                if (e > 1) return false;
            }
            else if (s[i] - '0' > 9 || s[i] - '0' < 0) return false;
            else ++num;
            
        }
        return true;
    }
};
