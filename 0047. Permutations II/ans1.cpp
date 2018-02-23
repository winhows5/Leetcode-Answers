/* time cost: 26ms (38.28%) */
/* time complexity: O(n^2)  */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
		vector<int> flags(nums.size(), 0);
		vector<int> content;
		sort(nums.begin(), nums.end());
		helper(nums, content, flags, result);
		return result;
    }
	
	void helper(vector<int>& nums, vector<int>& content, vector<int>& flags, vector<vector<int>>& result){
		if (content.size() == nums.size()) {
			result.push_back(content);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (!flags[i]){
				flags[i] = 1;
				content.push_back(nums[i]);
                int i1 = i;
                while (i < nums.size()-1 && nums[i+1] == nums[i])
                    ++i;
				helper(nums, content, flags, result);
				content.pop_back();
				flags[i1] = 0;
			}
		}
	}
};
