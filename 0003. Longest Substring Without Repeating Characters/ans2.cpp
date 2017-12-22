/* hashmap without loop */
/* time cost: 18ms (95.62%) */
/* time complexity: O(n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> hash;
        int longest = 0;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            if (hash.find(s[j]) != hash.end()) 
                i = max(i, (hash.find(s[j])->second+1));
            hash[s[j]] = j;
            longest = max(longest, (j-i+1));
        }
        return longest;
    }
};
