/* time cost: 21ms (99.86%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> list;
        for(int i = 0; i < strs.size(); ++i) {
            string comp(26, '0');
            for(int j = 0; j < strs[i].size(); ++j)
                ++comp[strs[i][j] - 'a'];
            list[comp].push_back(strs[i]);  
        }
        for (auto it = list.begin(); it != list.end(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
