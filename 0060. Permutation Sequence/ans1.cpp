/* time cost: 5ms (92.51%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> values(n+1, 1);
        for (int i = 1; i < n; ++i) values[i] = i * values[i - 1];
        
        bitset<9> valid(0x1ff);
        while (k > 0 && n > 0) {
            int ans_t = (k - 1) / values[n - 1];
            k = k - ans_t * values[n - 1];
            --n;
            
            int cnt = -1;
            int i = 0;
            for (; i < 9; ++i) { 
                if (valid[i]) ++cnt;
                if (cnt == ans_t) break;
            }

            valid[i] = 0;
            ans.push_back(i + '1');
        }
        return ans;
    }
};
