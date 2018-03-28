/* time cost: 4ms (100.00%) */
/* time complexity: O(n)    */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for (int i = 0; i < (1 << n); ++i) {
            ans.push_back(i ^ (i >> 1));   
        }
        return ans;
    }
};
