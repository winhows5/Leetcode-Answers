/* ASCII instead of hashmap */
/* time cost: 9ms (99.73%) */
/* time complexity: O(n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int* hash = new int[128]();
        for (int i=0; i<128; ++i)
            hash[i] = -1;
        int longest = 0;
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            i = max(hash[s[j]]+1, i);
            hash[s[j]] = j;
            longest = max(longest, (j-i+1));
        }
        return longest;
    }
};
