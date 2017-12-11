/* time cost: 9ms (99.72%) */
/* time complexity: O(n)   */

static int x =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
string convert(string s, int numRows) {
    if (numRows == 1) return s;
    vector<string> rows(numRows);
    string s2("");
    int longth = s.size();
    int no = 0;
    int i;
    for (i = 0; i < numRows; ++i) {
        
        if (no == longth) break;
        rows[i] += s[no];
        ++no;
        if (i == numRows - 1 && no != longth) {
            for (int j = i - 1; j > 0; --j) {
                if (no == longth) break;
                rows[j] += s[no];
                ++no;
            }
            i = -1;
        }
    }
    
    for (i = 0; i < numRows; ++i)
        s2 += rows[i];

    return s2;
}
};
