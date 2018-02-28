/* time cost: 6ms (68.09%) */
/* time complexity: O(n^2) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> temp_ans(n1 + n2, 0);
        for (int i = n1-1; i >= 0; --i) {
            for (int j = n2-1; j >= 0; --j) {
                int t = (num1[i] - '0') * (num2[j] - '0');
                int loc = n1-1 - i + n2-1 - j;
                temp_ans[loc] += t % 10;
                temp_ans[loc + 1] += t / 10;   
            }
            
        }
        for (int k = 0; k < n1 + n2; ++k) {
            if (temp_ans[k] > 9) {
                temp_ans[k + 1] += temp_ans[k] / 10;
                temp_ans[k] = temp_ans[k] % 10;
            }
        }
        int zeros = 0;
        while (temp_ans[n1 + n2 - 1 - zeros] == 0) {
            ++zeros;
            if (zeros == n1 + n2 -1) return to_string(temp_ans[0]);
        }
        string ans = "";
        for (int i = n1 + n2 - 1 - zeros; i >= 0; --i) {
            ans += (char)(temp_ans[i] + '0');
        }
        return ans;

    }
};
