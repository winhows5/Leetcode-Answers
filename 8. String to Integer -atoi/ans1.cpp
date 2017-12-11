/* time cost: 6ms (99.69%) */
/* time complexity: O(n)   */

// This problem is meaningless

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        int sgn = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                if (i == 0) continue;
                else if (str[i-1] != ' ') break;
                else continue;
            } 
            else if ((str[i] == '+' || str[i] == '-') && sgn) return 0;
            else if (str[i] == '+') sgn = 1;
            else if (str[i] == '-') sgn = -1;
            else if (str[i] >= '0' && str[i] <= '9') {
                if ( ans > INT_MAX / 10 || (ans == INT_MAX / 10 && str[i] - '0' > 7)) {
                    if (sgn != -1) return INT_MAX;
                    else return INT_MIN;
                }
                ans = ans * 10 + str[i] - 48;
            }
            
            else break;
        }
        if (!sgn) sgn = 1;
        return ans * sgn;
    }
};
