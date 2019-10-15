/* time cost: 0ms (100.00%) */
/* time complexity: O(n) */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int rob(vector<int>& nums) {
        int max_l1 = 0, max_l2 = 0, max_l3 = 0;
        
        for (int num : nums) {
            int temp = max_l1;
            max_l1 = maxValue(max_l1, max_l2+num);
            max_l2 = temp;
        }
        
//         if (nums.empty()) {
//             return 0;
//         } else if (nums.size() == 1) {
//             return nums[0];
//         } else if (nums.size() == 2) {
//             return nums[0]>nums[1] ? nums[0] : nums[1];
//         } else {
//             max_l1 = nums[2]+nums[0];      // the last one
//             max_l2 = nums[1];      // the second last one
//             max_l3 = nums[0];      // the third last one
            
//             for (int i=3; i < nums.size(); i++) {
//                 int temp = max_l1;
//                 max_l1 = maxValue(max_l1, max_l2+nums[i], max_l3+nums[i]);
//                 max_l3 = max_l2;
//                 max_l2 = temp;
                
//             }
//         }
        
        return maxValue(max_l1, max_l2);
    }
    
    int maxValue(int max_l1, int max_l2) {
        return max_l1 > max_l2 ? (max_l1) : (max_l2);
    }
};
