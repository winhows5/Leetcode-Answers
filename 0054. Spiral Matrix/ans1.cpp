/* time cost: 3ms (94.09%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>();
        int rows = matrix.size();
        int cols = matrix[0].size();
        int lays = (min(rows, cols)-1) / 2;
        int l = 0;
        
        vector<int> ans;
        while(l <= lays) {
            for (int i = l; i < cols - l; ++i) ans.push_back(matrix[l][i]); 
            
            if (l == rows - 1 - l) break;
            for (int i = l + 1; i < rows - 1 - l; ++i) ans.push_back(matrix[i][cols-1-l]);
            
            for (int i = cols - l - 1; i >= l; --i) ans.push_back(matrix[rows-1-l][i]);
            
            if (l == cols - 1 - l) break;
            for (int i = rows - 2 - l; i >= l + 1; --i) ans.push_back(matrix[i][l]);
            ++l;
        }
        return ans;
    }
};
