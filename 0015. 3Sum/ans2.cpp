/* time cost: Time Limit Exceeded */
/* time complexity: O(n^2*log(n))

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        map<int, int> found;
        int t;
        for(int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            t = - nums[i];
            found.clear();
            for(int j = i+1; j < nums.size(); ++j) {
                if (j - 2 > i && nums[j-2] == nums[j]) continue;
                if (found.find(t - nums[j]) != found.end()) {
                    ans.push_back({nums[i], t - nums[j], nums[j]});
                    found.erase(t - nums[j]);
                    continue;
                }
                found[nums[j]] = i;
            }
        }
        return ans;
    }
};
