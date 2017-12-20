/* time cost: 0ms (48.79%) */
/* time complexity: O(n^2) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ch = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans = {};
        vector<string> mid = {};
        vector<string> temp = {};
        for (int i = 0; i < digits.size(); ++i) {
            int num = digits[i] - '0';
            mid = ans;
            temp = ans;
            ans = {};
            for (int j = 0; j < ch[num].size(); ++j) {
                if (mid.empty()) {
                    string s{ch[num][j]};
                    mid.push_back(s);
                } else
                    for ( int k = 0; k < mid.size(); ++k) {
                        mid[k] += ch[num][j];
                    }
                ans.insert(ans.end(), mid.begin(), mid.end());
                mid = temp;
            }
        }
        return ans;
    }
};
