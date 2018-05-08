/* time cost : 7ms (99.79%) */
/* time complexity: O(n)    */

// I found a missed test case! 🤩
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> cons;
        int ans = 0;
        int tmp_l, tmp_r;
        for (int& c : nums) {
            if (cons[c] != 0)
                continue;
            else {
                cons[c] = 1;
                ans = max(ans, 1);
                if (c == INT_MAX) {
                    tmp_l = cons[c-1];
                    tmp_r = 0;
                }
                else if (c == INT_MIN) {
                    tmp_l = 0;
                    tmp_r = cons[c+1];
                }
                else {
                    tmp_l = cons[c-1];
                    tmp_r = cons[c+1];   
                }
                cons[c-tmp_l] = tmp_l + tmp_r + 1;
                cons[c+tmp_r] = tmp_l + tmp_r + 1;
                ans = max(ans, tmp_l + tmp_r + 1);
            }
        }
        return ans;
    }
};
