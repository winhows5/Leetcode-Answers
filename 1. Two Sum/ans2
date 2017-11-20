/* One-pass hash */
/* time cost: 6ms */
/* time complexity: O(n) */
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
