/* time cost: 242ms (25.93%) */
/* time complexity: O(m^2*n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int lghs = words.size();
        if (!lghs) return {};
        int lgh = words[0].size();
        vector<int> Ans;
        for (int i = 0; i < s.size() + 1 - lghs*lgh; ++i) {
            vector<int> found(lghs, 0);
            int foundno = 0;
            bool sgn = 1;
            int loc, cnt;
            while (sgn) {
                sgn = 0;
                for (int j = 0; j < lghs; ++j) {
                    if (found[j] == 1)
                        continue;
                    if (words[j] == s.substr(i + lgh*foundno, lgh)) {
                        sgn = 1;
                        found[j] = 1;
                        ++foundno;
                    }
                }
                if (foundno == lghs) {
                    Ans.push_back(i);
                    break;
                }
            }
        }
        return Ans;
    }
};
