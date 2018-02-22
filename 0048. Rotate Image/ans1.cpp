/* time cost: 5ms (33.22%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int lgh = matrix.size();
        for (int i = 0; i < lgh/2; ++i) {
            for (int j = i; j < lgh - i - 1; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[lgh-j-1][i];
                matrix[lgh-j-1][i] = matrix[lgh-i-1][lgh-j-1];
                matrix[lgh-i-1][lgh-j-1] = matrix[j][lgh-i-1];
                matrix[j][lgh-i-1] = temp;
            }
        }
        
    }
};
