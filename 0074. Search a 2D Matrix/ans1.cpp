/* time cost: 6ms (100.00%)   */
/* time complexity: O(log(n)) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;
        int cols = matrix[0].size();
        if (cols == 0) return false;
        
        int begin = 0, end = rows * cols - 1, mid;
        while (begin < end) {
            mid = (begin + end) / 2;
            if (matrix[mid/cols][mid%cols] > target)
                end = mid - 1;
            else if (matrix[mid/cols][mid%cols] < target)
                begin = mid + 1;
            else return true;
        }
        if (end < 0 || begin > rows * cols - 1) return false;
        return matrix[end/cols][end%cols] == target;
    }
};
