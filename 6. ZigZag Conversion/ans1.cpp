/* time cost: 15ms (99.32%) */
/* time complexity: O(n) */

static int x =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
string convert(string s, int numRows) {
    
    if (numRows == 1) return s;
    int *li = new int[numRows];
    string s2(s);
    int m, n;
    int i, j;
    int longth = s.size();
    int T = 2 * numRows - 2;
    
    m = longth % T;
    n = longth / T;
    if (m == 0) {
        for (i = 0; i < numRows; ++i) {
            li[i] = (i == 0 || i == numRows-1) ? n : 2*n;
        }
    }
    else if (m <= numRows) {
        for (i = 0; i < numRows; ++i) {
            if (i == 0) {
                li[i] = n + 1;
            }
            else if (i == numRows -1){
                li[i] = (m == numRows) ? n+1 : n;
            }
            else {
                li[i] = (m >= i+1) ? 2*n+1 : 2*n;
            }
        }
    }
    else {
        for (i = 0; i < numRows; ++i) {
            if (i == 0 || i == numRows-1) {
                li[i] = n + 1;
            }
            else {
                li[i] = (m >= 2*numRows-i-1) ? 2*n + 2 : 2*n + 1;
            }
        }
    }
    
    for (i = 0; i < longth; ++i) {
        m = (i+1) % T;
        n = (i) / T;
        int sum = 0;
        int no = 0;
        if (m > 0 && m <= numRows) {
            for (j = 0; j < m - 1; ++j)
                sum += li[j];
            no = (m == 1 || m == numRows) ? n :  2 * n;
        }
        else {
            if (m == 0) {
                sum = li[0];
            }
            else
                for (j = 0; j < T - m + 1; ++j)
                    sum += li[j];
            no = (numRows == 2) ? n : 2*n + 1;
        }
        s2[sum + no] = s[i];
        
    }

    return s2;
}
};
