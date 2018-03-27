/* time cost: 12ms (100.00%) */
/* time complexity: O(mn)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool search(vector<vector<char>>& board, string &word, int i, int j, int pos) {

        if (pos == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        bool ans = false;
        if (board[i][j] == word[pos]) {
            char t = board[i][j];
            board[i][j] = '\0';
            ans = search(board, word, i+1, j, pos+1) || 
                  search(board, word, i, j+1, pos+1) ||
                  search(board, word, i-1, j, pos+1) || 
                  search(board, word, i, j-1, pos+1);  
            board[i][j] = t;   
        } 
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if (row == 0) return false;
        int col = board[0].size();
        if (col == 0) return false;
        if (word.size() == 0) return true;
        
        vector<vector<int>> valid(row, vector<int>(col, -1));
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j) {
                if(search(board, word, i, j, 0))
                    return true;
            }
        
        return false;
    }
};
