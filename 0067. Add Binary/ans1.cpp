/* time cost: 4ms (99.37%) */
/* time complexity: O(m+n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string addBinary(string a, string b) {
        int w = 0;
        string ans = "";
        int i = a.size() - 1; 
        int j = b.size() - 1;
        while (i >= 0 || j >= 0) {
            if (i < 0) {
                if (b[j] + w == '2') {
                    ans = '0' + ans;
                    w = 1;
                }
                else {
                    ans = (char)(b[j] + w) + ans; 
                    w = 0;
                }
            }
            else if (j < 0) {
                if (a[i] + w == '2') {
                    ans = '0' + ans;
                    w = 1;
                }
                else {
                    ans = (char)(a[i] + w) + ans; 
                    w = 0;
                }
            }
            else if (a[i] == '0' && b[j] == '0') {
                ans = (char)('0' + w) + ans;
                w = 0;    
            }
            else if (a[i] == '1' && b[j] == '1') {
                ans = (char)('0' + w) + ans;
                w = 1; 
            }
            else ans = w ? ('0' + ans) : ('1' + ans);

            --i;
            --j;
        }
        return w ? ('1' + ans) : ans;
    }
};
