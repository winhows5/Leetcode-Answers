/* time cost: 6ms (100.00%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(string &s, int begin, int end) {
        while (begin <= end)
            if (s[begin++] != s[end--])
                return false;
        return true;
    }
    void partition_iteration(string &s, vector<vector<string>> &ans, vector<string> &tmp, int start) {
        if (start == s.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                tmp.push_back(s.substr(start, i-start+1));
                partition_iteration(s, ans, tmp, i+1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        partition_iteration(s, ans, tmp, 0);
        return ans;
    }
};
