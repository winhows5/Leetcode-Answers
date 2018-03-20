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
            if (j >= 0) {
                w += b[j] - '0';
                --j;
            }
            if (i >= 0) {
                w += a[i] - '0';
                --i;
            }
           
            ans = (w % 2) ? ('1' + ans) : ('0' + ans);
            w = w / 2;          
        }
        return w ? ('1' + ans) : ans;
    }
};
