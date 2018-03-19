/* time cost: 3ms (100.00%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lgh = 0;
        if (s.empty()) return lgh;
        int i = s.size() - 1;
        while (s[i] == ' ') --i;
        for (; i >= 0; --i) {
            if (s[i] != ' ') ++lgh;
            else return lgh;
            if (i == 0) return lgh;
        }
        return lgh;
    }
};
