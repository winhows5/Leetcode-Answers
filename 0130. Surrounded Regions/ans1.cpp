/* time cost: 13ms (100.00%) */
/* time complexity: O(mn)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void changeMark(vector<vector<char>>& board, vector<vector<int>>& mark, int x, int y, int direc) {
        if (x < 0 || x > board.size() - 1) return;
        if (y < 0 || y > board[0].size() - 1) return;
        if (mark[x][y] == 1 && board[x][y] == 'O') {
            mark[x][y] = 0;
            if (direc != 1) changeMark(board, mark, x-1, y, 3);
            if (direc != 2) changeMark(board, mark, x, y-1, 4);
            if (direc != 3) changeMark(board, mark, x+1, y, 1);
            if (direc != 4) changeMark(board, mark, x, y+1, 2);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.size() <= 2 || board[0].size() <= 2) return;
        int row = board.size(), col = board[0].size();
        vector<vector<int>> mark(row, vector<int>(col, 1));
        for (int i = 0; i < col; ++i) {
            changeMark(board, mark, 0, i, 0);
            changeMark(board, mark, row-1, i, 0);
        }
        for (int i = 1; i < row-1; ++i) {
            changeMark(board, mark, i, 0, 0);
            changeMark(board, mark, i, col-1, 0);
        }
        for (int i = 1; i < row-1; ++i)
            for (int j = 1; j < col-1; ++j)
                if (mark[i][j] == 1)
                    board[i][j] = 'X';
    }
};
