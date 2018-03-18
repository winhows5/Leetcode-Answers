/* time cost: 12ms (99.55%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
        int longth = nums.size();
        int steps = 0;
        int max;
        int max_pos;
        while (true) {
            max = 0;
            max_pos = cur;
            steps = cur + nums[cur];
            while(steps >= cur) {
                if (steps + nums[steps] > max) {
                    max = steps + nums[steps];
                    max_pos = steps;
                }    
                --steps;
            }
            cur = max_pos;
            if (cur >= longth - 1) return true;
            if (nums[cur] == 0) return false;
        }
    }
};
