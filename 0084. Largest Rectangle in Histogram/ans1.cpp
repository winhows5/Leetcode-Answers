/* time cost: 7ms (99.91%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> ind;
        heights.push_back(0);
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (ind.size() > 0 && heights[ind.top()] > heights[i]) {
                int h = heights[ind.top()];
                ind.pop();
                int pos = ind.empty() ? 0 : ind.top()+1;
                ans = max(ans, h * (i - pos));
            }
            ind.push(i);
        }
        return ans;
    }
};


