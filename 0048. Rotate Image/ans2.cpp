/* time cost: 5ms (37.22%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0;i < matrix.size(); ++i){
            for (int j = i+1; j < matrix.size(); ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
