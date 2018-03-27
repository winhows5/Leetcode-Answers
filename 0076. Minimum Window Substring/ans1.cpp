/* time cost: 4ms (100.00%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string minWindow(string s, string t) {
        int map[128]{};
        for (char c : t) ++map[c];
        int cnt = t.size(), begin = 0, end = 0, head = 0, lngth = INT_MAX;
        while (end < s.size()) {
            if (map[s[end]] > 0) --cnt;
            --map[s[end]];
            ++end;
            while (cnt == 0) {
                if (end - begin < lngth) {
                    head = begin;
                    lngth = end - begin;
                }
                ++map[s[begin]];
                if (map[s[begin]] > 0) ++cnt;
                ++begin;    
            }
        }
        return lngth == INT_MAX ? "" : s.substr(head, lngth);
    }
};
