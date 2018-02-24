/* time cost: 7ms (100.00%)  wow! */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int jump(vector<int>& nums) {
        int lgh = nums.size();
        if (lgh <= 1) return 0;
        int cnt = 0;
        int pre = 0, cur;
        while (true) {
            cur = pre;
            for (int i = 1; i <= nums[pre]; ++i) {
                if (cur + nums[cur] < nums[i + pre] + i + pre) {
                    cur = i + pre;
                }
                if (cur + nums[cur] >= lgh-1) {
                    if (pre + nums[pre] >= lgh-1) return (cnt + 1);
                    else return (cnt + 2);
                }
            }
            ++cnt;
            pre = cur;
        }
        
        
    }
};
