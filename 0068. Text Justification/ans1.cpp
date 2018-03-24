/* time cost: 2ms (100.00%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int nums = words.size();
        int pre = 0, cur = 0;
        if (!nums) return vector<string>(1, string(maxWidth, ' '));
        while (cur < nums) {
            int lgh = 0;
            string ans_t = "";
            while (lgh + words[cur].size() < maxWidth) {
                // if (words[i].size() < maxWidth) return vector<string>("");
                lgh += words[cur].size() + 1;
                ++cur;
                if (cur == nums) {
                    for (int i = pre; i < cur; ++i) {
                        ans_t += (words[i] + ' ');
                    }
                    ans_t += string(maxWidth-lgh,' ');
                    ans.push_back(ans_t);
                    return ans;
                }
            }
            if (lgh + words[cur].size() == maxWidth) {
                for (int i = pre; i < cur; ++i) {
                    ans_t += (words[i] + ' ');
                }
                ans_t += words[cur];
                ans.push_back(ans_t);
                ++cur;
                pre = cur;
            }
            else {
                --lgh;
                if (cur - pre - 1 == 0) {
                    ans_t += words[cur-1] + string(maxWidth - lgh, ' ');
                    ans.push_back(ans_t);
                    pre = cur;
                    continue;
                }
                int s_times = (maxWidth - lgh) / (cur - pre - 1) + 1;
                int s_nums = (maxWidth - lgh) % (cur - pre - 1);
                for (int i = pre; i < cur - 1; ++i) {
                    ans_t += (words[i] + string(s_times, ' '));
                    if (s_nums) {
                        ans_t += ' ';
                        --s_nums;
                    }
                }
                ans_t += words[cur-1];
                ans.push_back(ans_t);
                pre = cur;
            }
        }
        return ans;
    }
};
