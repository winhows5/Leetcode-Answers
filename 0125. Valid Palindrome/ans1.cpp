/* time cost: 6ms (99.86%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size()-1; i <= j;) {
            while (!((48 <= s[i] && s[i] <= 57) || 
                     (97 <= s[i] && s[i] <= 122) || (65 <= s[i] && s[i] <= 90)) && i < j)
                ++i;
            while (!((48 <= s[j] && s[j] <= 57) || 
                     (97 <= s[j] && s[j] <= 122) || (65 <= s[j] && s[j] <= 90)) && i < j)
                --j;
            if (97 <= s[i] && s[i] <= 122)
                s[i] -= 32;
            if (97 <= s[j] && s[j] <= 122)
                s[j] -= 32;
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};
