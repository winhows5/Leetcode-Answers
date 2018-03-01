/* time cost: 8ms (98.43%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = 0, right_max = 0;
        int ans = 0;
        int left = 0, right = height.size()-1;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < left_max) {
                    ans += left_max - height[left];
                }
                else left_max = height[left];
                ++left;
            }
            else {
                if (height[right] < right_max) {
                    ans += right_max - height[right];
                }
                else right_max = height[right];
                --right;
            }
        }
        return ans;
    }
};
