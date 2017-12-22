/* dynamic programming     */
/* time cost: 3ms (99.96%) */
/* time complexity: O(mn)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    bool d[m+1][n+1];
    for(int i = m; i >= 0; --i)
        for (int j = n; j >=0; --j) {
            d[i][j] = false;
        }

    bool front;
    for(int i = m; i >= 0; --i)
        for (int j = n; j >= 0; --j) {
            front = i < m && j < n && (s[i] == p[j] || p[j] == '.');
            if (i == m && j == n) {d[i][j] = true; continue;}
            if (p[j+1] == '*'){
                if(j + 2 <= n)
                    d[i][j] = d[i][j+2] || (front && d[i+1][j]);
                else d[i][j] = front && d[i+1][j];
            }
            else d[i][j] = front && d[i+1][j+1];
        }

    return d[0][0];
    
}
};
