/* time cost: 3ms (88.80%) */
/* time complexity: O(mn)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int strStr(string haystack, string needle) {
        int s = needle.size();
        if (haystack.size() < s) return -1;
        for (int i = 0; i < haystack.size() - s + 1; ++i) {
            if (haystack.substr(i, s) == needle)
                return i;
        }
        return -1;
    }
};
