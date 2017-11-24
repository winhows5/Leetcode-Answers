/* loop and skip */
/* time cost: 462ms (5.63%) */
/* time complexity: O(n^3) */

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<char, int> hash;
    int longest = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i; j < s.size(); ++j) {
            if (hash.find(s[j]) != hash.end()) {
                longest = longest>hash.size() ? longest : (j-i);
                i = hash.find(s[j])->second;
                hash.clear();
                break;
            }
            if (j == s.size() - 1) {
                longest = longest>hash.size() ? longest : (j-i+1);
                i = (int)s.size();
                hash.clear();
            }
            hash[s[j]] = j;
        }
    }
    return longest;
  }
}
