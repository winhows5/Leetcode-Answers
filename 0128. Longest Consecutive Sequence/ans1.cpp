/* time cost : 7ms (99.79%) */
/* time complexity: O(n)    */

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
        for (int& c : nums) {
            if (cons.find(c) != cons.end())
                continue;
            else {
                cons[c] = 1;
                if (c == INT_MAX) 
                    if (cons.find(c-1) != cons.end()) {
                        int tmp = cons[c-1];
                        cons[c] = tmp+1;
                        cons[c-tmp] = tmp+1;
                        ans = max(ans, tmp+1);
                }
                else if (c == INT_MIN) 
                    if (cons.find(c+1) != cons.end()) {
                        int tmp = cons[c+1];
                        cons[c] = tmp+1;
                        cons[c+tmp] = tmp+1;
                        ans = max(ans, tmp+1);
                }
                else {
                    if (cons.find(c-1) != cons.end() && cons.find(c+1) != cons.end()) {
                        int tmp_l = cons[c-1];
                        int tmp_r = cons[c+1];
                        cons[c-tmp_l] = tmp_l + tmp_r + 1;
                        cons[c+tmp_r] = tmp_l + tmp_r + 1;
                        ans = max(ans, tmp_l + tmp_r + 1);
                    }
                    else if (cons.find(c-1) != cons.end()) {
                        int tmp = cons[c-1];
                        cons[c] = tmp+1;
                        cons[c-tmp] = tmp+1;
                        ans = max(ans, tmp+1);
                    }
                    else if (cons.find(c+1) != cons.end()) {
                        int tmp = cons[c+1];
                        cons[c] = tmp+1;
                        cons[c+tmp] = tmp+1;
                        ans = max(ans, tmp+1);
                    }
                }
            }
        return ans;
        }
    }
};
