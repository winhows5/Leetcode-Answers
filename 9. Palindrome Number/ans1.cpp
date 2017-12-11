/* time cost: 42ms (99.87%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        string s = to_string(x);
        char c;
        for (int i=0, j=s.size()-1; i < j; ++i, --j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
        
    }
};
