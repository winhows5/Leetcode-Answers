/* One-pass hash */
/* time cost: 3ms (99.53%) */
/* time complexity: O(n) */

static int x = [](){ 
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    return 0; 
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hmap;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (hmap.find(target - nums[i]) != hmap.end()) { 
                ans.push_back(hmap[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            
            hmap[nums[i]] = i;
        }
    }
};
