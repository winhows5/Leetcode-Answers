/* time cost: 9ms (49.53%) */
/* time complexity: O(n)   */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size < 3) return 0;
        int l_max[size], r_max[size];
        l_max[0] = height[0];
        for (int i = 1; i < size; ++i)
            l_max[i] = max(l_max[i-1], height[i]);
        r_max[size-1] = height[size-1];
        for (int i = size-2; i >= 0; --i)
            r_max[i] = max(r_max[i+1], height[i]);
        int ans = 0;
        for (int i = 0; i < size; ++i)
            ans += min(l_max[i], r_max[i]) - height[i];
        return ans;
    }
};
