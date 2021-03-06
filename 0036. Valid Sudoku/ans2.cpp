/* time cost: 12ms (97.21%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<char> valid = {'9','8','7','6','5','4','3','2','1'};
    int longth = 9;
    bool isValidNine(vector<char>& nine) {
        for (int i = 0; i < longth; ++i) {
            if (count(nine.begin(), nine.end(), valid[i]) > 1)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < longth; ++i) {
            if (!isValidNine(board[i]))
                return false;
            
            vector<char> col;
            for (int j = 0; j < longth; ++j) {
                col.push_back(board[j][i]);
            }
            if (!isValidNine(col))
                return false;
            
            vector<char> mat;
            for (int j = 0; j < 3; ++j) 
                for (int k = 0; k < 3; ++k) {
                    mat.push_back(board[i/3 * 3 + j][i%3 * 3 + k]);
                }
            if (!isValidNine(mat))
                return false;
        }
        
        return true;
    }
};
