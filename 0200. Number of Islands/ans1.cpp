/* time cost: 8ms (99.19%) */
/* time complexity: O(n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int w;
    int h;
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int num = 0;
        w = grid[0].size();     // width
        h = grid.size();        // highth
        for (int i = 0; i<h; i++) {
            for (int j = 0; j<w; j++) {
                if (grid[i][j] == '1') {
                    spread(grid, i, j);
                    num++;
                }
            }
        }
        return num;
    }
    void spread(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= h || j >= w) return;
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        spread(grid, i-1, j);
        spread(grid, i+1, j);
        spread(grid, i, j-1);
        spread(grid, i, j+1);
        
    }
};


